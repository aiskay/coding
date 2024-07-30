#include <iostream>
#include "stack.hpp"
using namespace std;



int main()
{
    Stack<int> S;

    int&& data = 3;
    cout << data << endl;

    //int dataConv( move(data) );
    int dataConv = move(data);
    cout << dataConv << endl;
}