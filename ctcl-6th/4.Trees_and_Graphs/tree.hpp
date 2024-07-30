#ifndef _H_TREE
#define _H_TREE


template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
    Node( T d ): data(d), left(nullptr), right(nullptr) {}
};


template <typename T>
void preOrder( Node<T>* node )
{
	if( node == NULL ) return;

	cout<< node->data <<" ";
	preOrder( node->left );
	preOrder( node->right );
}




#endif