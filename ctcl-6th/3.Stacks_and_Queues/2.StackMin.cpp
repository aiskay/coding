#include <cmath>
#include <iostream>
#include <random>
#include "stack.hpp"
using namespace std;

template <typename T>
class StackMin
{
    private:
        Stack<T> stack;
        Stack<T> minStack;
    
    public:
        T& peek() { return stack.peek(); }
        T& min()  { return minStack.peek(); }
        bool isEmpty() const { return stack.isEmpty(); }

        template <typename U>
        void push( U&& data );
        void print();
        T pop();
        class StackIsEmptyException {};
};


template <typename T>
template <typename U>
void StackMin<T>::push( U&& data )
{
    if( minStack.isEmpty() || data <= minStack.peek() ) minStack.push( data );
    stack.push( forward<U>(data) );
}


template <typename T>
T StackMin<T>::pop()
{
    T value = stack.pop();
    if( value == min() ) minStack.pop();
    stack.pop();    
}

template <typename T>
void StackMin<T>::print()
{
    stack.print();
    minStack.print();
}



int main()
{
    mt19937 mt(2);
    uniform_int_distribution<> rand(0,10);

    StackMin<int>* Smin = new StackMin<int>;
    for( int i = 0; i < 10; ++i ) Smin->push( rand(mt) );
    
    Smin->print();
}