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
        Node<T>* head;
        explicit LinkedList(): head(nullptr) {}
        explicit LinkedList( T d ): head(new Node<T>(d)) {}
        
        void appendNode( T d );  // 最後尾に Node を追加
        void insertNode( T d );  // 先頭に Node を追加
};

template <typename T>
void LinkedList<T>::appendNode( T d )
{
    Node<T>* new_Node = new Node<T>( d );
    
    if( head == nullptr ) head = new_Node;
    else
    {
        Node<T>* curr = head;
        while( curr->next ) curr = curr->next;
        curr->next = new_Node;
    }
}

template <typename T>
void LinkedList<T>::insertNode( T d )
{
    Node<T>* new_Node = new Node<T>( d );
    new_Node->next = head;
    head = new_Node;
}


template <typename T>
void printList( const LinkedList<T>& A, int k = 0 )
{
    int order = 0;
    Node<T>* curr = A.head;
    while( curr )
    {
        if( order >= k ) cout << curr->data << " --> ";
        curr = curr->next;
        order++;
    }
    cout << "nullptr" << endl;
}


template <typename T>
Node<T>* sumListsRecursive( Node<T>* n1, Node<T>* n2, int kuriage = 0 )
{
    if( n1 == nullptr && n2 == nullptr && kuriage == 0 ) return nullptr;
    int value = kuriage;

    if( n1 ) value += n1->data;
    if( n2 ) value += n2->data;
    
    Node<T>* digitSumNode = new Node<T>( value % 10 );

    if( n1 || n2 )
    {
        Node<T>* more = sumListsRecursive( n1 == nullptr ? nullptr : n1->next,
                                           n2 == nullptr ? nullptr : n2->next,
                                           value / 10 );
        digitSumNode->next = more;
    }
    
    return digitSumNode;
}

template <typename T>
LinkedList<T>* sumLists( const LinkedList<T>& A, const LinkedList<T> & B )
{   
    LinkedList<T>* LinkedList_sum = new LinkedList<T>;
    
    LinkedList_sum->head = sumListsRecursive( A.head, B.head );

    return LinkedList_sum;
}


int main()
{
    random_device rnd;
    mt19937 mt(2);
    uniform_int_distribution<> rand(0,9);

    LinkedList<int>* A = new LinkedList<int>;
    LinkedList<int>* B = new LinkedList<int>;
    for( int i = 0; i < 4; ++i ) 
    {
        A->appendNode( rand(mt) );
        B->appendNode( rand(mt) );
    }

    printList( *A );
    printList( *B );

    printList( *sumLists( *A, *B ) );

    delete A;
    delete B;
}