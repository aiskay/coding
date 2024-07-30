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
        // ( 実装の仕方にも依ると思う )
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
    curr->next = curr->next->next;
}


template <typename T>
void printList( LinkedList<T>& A )
{
    Node<T>* curr = &A.node;
    while( curr )
    {
        cout << curr->data << " --> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}


template <typename T>
void RemoveDups( LinkedList<T>& A )
{
    if( ! A.node.next ) return;

    // [key, value] = [Node.data, isAppeared] でHashmapに追加
    unordered_map<int, bool> node_map;
    Node<T>* prev = &A.node;
    Node<T>* curr = A.node.next;
    
    node_map[prev->data] = true;
    while( curr )
    {
        // cout << curr << endl;
        // node_map 内に存在しない data を持つ Node まで curr を移動
        while( curr && node_map.find(curr->data) != node_map.end() ){
            curr = curr->next;
        }
        // prev と curr をつなぐ
        prev->next = curr;
        prev = curr;
        // node_map にkeyを代入して curr を進める
        if( curr )
        {
            node_map[curr->data] = true;
            curr = curr->next;
        }
    }
}


int main()
{
    random_device rnd;
    mt19937 mt(1);
    uniform_int_distribution<> rand(0,5);

    LinkedList<int> A( 3 );
    for( int i = 0; i < 8; ++i ) A.appendNode( rand(mt) );

    printList( A );

    RemoveDups( A );
    //A.deleteNode( 2 );

    printList( A );
}