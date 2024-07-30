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

template <typename T>
void deleteMiddleNode( Node<T>* node )
{
    Node<T>* next_Node = node->next;
    node->data = next_Node->data;
    node->next = next_Node->next;
    delete next_Node;
}


int main()
{
    random_device rnd;
    mt19937 mt(1);
    uniform_int_distribution<> rand(0,5);

    LinkedList<int> A( 3 );
    for( int i = 0; i < 8; ++i ) A.appendNode( rand(mt) );

    printList( A );
    deleteMiddleNode( A.node.next->next );
    printList( A );
}