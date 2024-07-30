#include <iostream>
#include "graph.hpp"
using namespace std;


int main()
{
    Graph g(6);	
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

/*	
	Test graph :
	0 <---4---->1
	^ 			^
	|			|
	|			|
    5---->2---->3 
*/
    cout << boolalpha << g.isRoute(5,4) << endl; // false
    cout << boolalpha << g.isRoute(5,1) << endl; // true

}