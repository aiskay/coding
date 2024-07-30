#include <memory>
#include <iostream>
#include <random>
using namespace std;


template <typename T>
class Node
{
    public:
        T data;                    // 保持するデータ
        unique_ptr<Node<T>> next;  // 次のノードを指すポインタ
        explicit Node( T d ): data(d){}
};


// 単方向結合リスト ( Singly Linked List )
template <typename T>
class LinkedList
{
    private:
    public:
        Node<T> node;
        explicit LinkedList( T d ): node(d){}
        
        void appendNode( T );
        void deleteNode( int );
};

// 最後尾に Node を追加
template <typename T>
void LinkedList<T>::appendNode( T d )
{
    Node<T>* new_Node = new Node<T>( d );

    Node<T>* curr = &this->node;
    while( curr->next ) curr = curr->next.get();
    curr->next.reset( new_Node );
}

// Linked List のデータを表示
template <typename T>
void printList( LinkedList<T>& A )
{
    Node<T>* curr = &A.node;
    while( curr )
    {
        cout << curr->data << " --> ";
        curr = curr->next.get();
    }
    cout << "nullptr" << endl;
    delete curr;
}


int main()
{
    LinkedList<int> A( 3 );

    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand(-10,10);
    for( int i = 0; i < 10; ++i ) A.appendNode( rand(mt) );
    
    printList( A );
}