#include <iostream>
#include <vector>
#include "tree.hpp"
#include "list.hpp"
using namespace std;


template <typename T>
void createLevelLinkedList( Node<T>* root, vector<LinkedList<Node<T>>>* lists, int level )
{
    if( root == NULL ) return;

    LinkedList<Node<T>>* list;
    if( lists->size() == level ){
        list = new LinkedList<Node<T>>;
        lists->push_back( *list );
    }else 

    list->appendNode( *root );
    createLevelLinkedList( root->left, lists, level+1 );
    createLevelLinkedList( root->right, lists, level+1 );
}

template <typename T>
vector<LinkedList<Node<T>>> createLevelLinkedList( Node<T>* root )
{
    vector<LinkedList<Node<T>>> lists;
    createLevelLinkedList( root, &lists, 0 );
    return lists;
}


int main()
{
    Node<int> root( 10 );

    vector<LinkedList<Node<int>>> lists = createLevelLinkedList( &root );

}