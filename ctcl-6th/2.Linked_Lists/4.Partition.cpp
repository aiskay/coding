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
        Node(){}
        explicit Node( T d ): data(d){}
};

template <typename T>
class LinkedList
{
    private:
    public:
        Node<T>* node = nullptr;
        explicit LinkedList(){}
        explicit LinkedList( T d ): node(new Node<T>(d)){}
        
        void appendNode( T d );  // 最後尾に Node を追加
        void insertNode( T d );  // 先頭に Node を追加
};

template <typename T>
void LinkedList<T>::appendNode( T d )
{
    Node<T>* new_Node = new Node<T>( d );
    
    if( this->node == nullptr ) this->node = new_Node;
    else
    {
        Node<T>* curr = this->node;
        while( curr->next ) curr = curr->next;
        curr->next = new_Node;
    }
}

template <typename T>
void LinkedList<T>::insertNode( T d )
{
    Node<T>* new_Node = new Node<T>( d );
    new_Node->next = this->node;
    this->node = new_Node;
}


template <typename T>
void printList( LinkedList<T>& A, int k = 0 )
{
    int order = 0;
    Node<T>* curr = A.node;
    while( curr )
    {
        if( order >= k ) cout << curr->data << " --> ";
        curr = curr->next;
        order++;
    }
    cout << "nullptr" << endl;
}


template <typename T>
LinkedList<T>* partition( LinkedList<T>* A, int x )
{
    LinkedList<T>* partedA = new LinkedList<T>;
    Node<T>* curr = A->node;

    while( curr )
    {
        if( curr->data < x ) partedA->insertNode( curr->data );
        else partedA->appendNode( curr->data );
        curr = curr->next;
    }
    delete A;
    return partedA;
}


int main()
{
    random_device rnd;
    mt19937 mt(1);
    uniform_int_distribution<> rand(0,5);

    LinkedList<int>* A = new LinkedList<int>( 3 );
    for( int i = 0; i < 6; ++i ) A->appendNode( rand(mt) );

    printList( *A );

    A = partition( A, 4 );

    printList( *A );
}