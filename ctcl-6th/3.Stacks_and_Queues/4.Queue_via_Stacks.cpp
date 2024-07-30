#include <cmath>
#include <iostream>
#include <random>
#include "stack.hpp"
using namespace std;


template <typename T>
class MyQueue
{
    private:
        Stack<T> newValues, reversed;
        void move( Stack<T>& from, Stack<T>& to );
    
    public:
        template <typename U>
        void add( U&& data ) { newValues.push( forward<U>(data) ); }
        T peek();
        T remove();
        bool isEmpty() { return newValues.isEmpty() && reversed.isEmpty(); }
        void print() { newValues.print(); reversed.print(); }
};

template <typename T>
void MyQueue<T>::move( Stack<T>& from, Stack<T>& to )
{
    while( !from.isEmpty() ) to.push( from.pop() );
}

template <typename T>
T MyQueue<T>::peek()
{
    if( reversed.isEmpty() ) move( newValues, reversed );
    return reversed.peek();
}

template <typename T>
T MyQueue<T>::remove()
{
    if( reversed.isEmpty() ) move( newValues, reversed );
    return reversed.pop();
}


int main()
{
    mt19937 mt(1);
    uniform_int_distribution<> rand(0,10);

    MyQueue<int> q;
    for( int i = 0; i < 9; ++i ) q.add( rand(mt) );
    
    //q.print();
    while( !q.isEmpty() ) cout << q.remove() << " ";
    cout << endl;

}