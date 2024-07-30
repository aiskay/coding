#include <iostream>
#include <utility>  // move, forward などが定義されている

// C+11から右辺値参照 && と左辺値参照 & が明確に区別されている
// 右辺値参照、左辺値参照の詳しい説明は 
// https://qiita.com/rinse_/items/ad0cc7e351e836595c94
// Stackでは、一番上に入れて一番上から取り出す (last-in first-out)
template <typename T>
class Stack
{
    private:
        struct Node
        {
            T data;
            Node* next = nullptr;
            // コンストラクタの引数を右辺値・左辺値ともに定義する
            Node(      T&& d, Node* n ): data(std::move(d)), next(n) {}
            Node( const T& d, Node* n ): data(d),            next(n) {}
        };
        Node* top;
        size_t stackSize;
    
    public:
        Stack()               : top(nullptr), stackSize(0) {}
        Stack( Stack&& other ):
        top(std::move(other.top)), stackSize(std::move(other.stackSize)) {} 

        ~Stack(){ while(!isEmpty()) pop(); }

        template <typename U>
        void push( U&& data );
        T& peek();
        T pop();
        void print();
        bool isEmpty() const { return !top; }
        size_t size()  const { return stackSize; }
        class StackIsEmptyException {};
};


// テンプレートクラスでテンプレートメンバ関数を、クラスの外側で実装するには、
// template <typename T, U>
// ではなく、別々に宣言しないとだめ
template <typename T>
template <typename U>
void Stack<T>::push( U&& data )
{
    // std::forwad<U>(v) は Node の引数に応じて
    // 左辺値<->右辺値 のキャストを適切に行ってくれる関数である
    auto n = new Node(std::forward<U>(data), top);
    top = n;
    ++stackSize;
}

template <typename T>
T& Stack<T>::peek()
{
    if( !top ) throw StackIsEmptyException();
    return top->data;
}

template <typename T>
T Stack<T>::pop()
{
    if (!top ) throw StackIsEmptyException();
    
    auto data(std::move(top->data)); // data に top->data を代入
    Node* n = top;
    top = n->next;
    delete n;
    --stackSize;
    return data;
}

// 動作確認用、本当は必要ない
template <typename T>
void Stack<T>::print()
{
    if( !top ) throw StackIsEmptyException();

    auto curr = top;
    std::cout << "top -> ";
    while( curr ){
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr" << std::endl;
}