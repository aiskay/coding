#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
using namespace std;



template <typename T>
class Node
{
    public:
        T data;
        Node<T>* next = nullptr;
        // 次のノードを指すポインタ
        // unique_ptr で実装すると、途中の Node を解放する際
        // 数珠つなぎ的に全ての next が解放されてしまいうまくいかない
        // ( 実装の仕方に依るのかも？ )
        explicit Node( T d ): data(d){}
};

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

template <typename T>
void LinkedList<T>::appendNode( T d )
{
    Node<T>* new_Node = new Node<T>( d );

    Node<T>* curr = &this->node;
    while( curr->next ) curr = curr->next;
    curr->next = new_Node;
}

// n 番目の Node を削除する
template <typename T>
void LinkedList<T>::deleteNode( int n )
{
    int order = 0;
    Node<T>* curr = &this->node;
    while( order != n-1 )
    {
        curr = curr->next;
        order++;
    }
    delete curr->next;
    curr->next = curr->next->next;
}


template <typename T>
void printList( LinkedList<T>& A, int k = 0 )
{
    int order = 0;
    Node<T>* curr = &A.node;
    while( curr )
    {
        if( order >= k ) cout << curr->data << " --> ";
        curr = curr->next;
        order++;
    }
    cout << "nullptr" << endl;
}

// 再帰での実装
// curr が最後まで到達すると +1 されるような index i を作り、
// i == k となったときにその Node のアドレスを返す
template <typename T>
Node<T>* kthToLastHelper( Node<T>* node, int k, int& i )
{
    if( node == nullptr ) return nullptr;
    Node<T>* curr = kthToLastHelper( node->next, k, i );
    i++;
    if( i == k ) return node;
    else return curr;
}

template <typename T>
Node<T>* kthToLastRecursive( LinkedList<T> A, int k )
{
    int i = 0;
    return kthToLastHelper( &A.node, k, i );
}

// 2つのポインタの iteration での実装
// 片方のポインタ p1 をk番目の Node まで進める
// その後、 p1, p2 を同時に進めると p1 が最後まで進んだとき
// p2 は前からL-k番目、つまり後ろからk番目を指している
template <typename T>
Node<T>* kthToLastIterative( LinkedList<T>& A, int k )
{
    Node<T>* p1 = &A.node;
    Node<T>* p2 = &A.node;

    for( int i = 0; i < k; i++ )
    {
        if( p1 ) p1 = p1->next;
        else return nullptr;
    }

    while( p1 )
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}


int main()
{
    random_device rnd;
    mt19937 mt(1);
    uniform_int_distribution<> rand(0,5);

    LinkedList<int> A( 3 );
    for( int i = 0; i < 8; ++i ) A.appendNode( rand(mt) );

    printList( A );
    
    cout << kthToLastRecursive( A, 1 )->data << endl;
    cout << kthToLastIterative( A, 3 )->data << endl;
}