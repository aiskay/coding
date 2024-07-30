#include <iostream>
#include <vector>
#include "tree.hpp"
using namespace std;



template <typename T>
Node<T>* createMinimalBST( vector<int>& arr, int low, int high )
{
    if( low > high ) return NULL;
    
    int mid = (low + high) / 2;
    Node<T>* node = new Node<T>(arr[mid]);
    node->left  = createMinimalBST<T>( arr, low, mid - 1 );
    node->right = createMinimalBST<T>( arr, mid + 1, high );
    return node;
}

template <typename T>
Node<T>* createMinimalBST( vector<int>& arr )
{
    if( arr.size() == 0 ) return NULL;
    return createMinimalBST<T>( arr, 0, arr.size() - 1 );
}


int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};

    vector<int> arr( A, A+sizeof(A) / sizeof(A[0]) );
    /*
        Convert List to BST {1,2,3,4,5,6,7}
                         4
                      /     \
                    2         6
                  /   \     /   \
                 1     3   5     7
    */
    Node<int> *root = createMinimalBST<int>(arr);
    cout << "PreOrder Traversal of constructed BST : ";
    preOrder( root );
    delete root;
}