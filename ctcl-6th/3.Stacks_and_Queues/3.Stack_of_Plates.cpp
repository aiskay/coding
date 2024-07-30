#include <cmath>
#include <iostream>
#include <random>
#include "stack.hpp"
using namespace std;

// 注意: メモリのエラーが出る

//       Stack Stack ...
//         o    o
//         o    o    o
// Stack:  o -- o -- o - ...
//                   ↓
template <typename T, size_t Capacity>
class SetOfStacks 
{
    private:
        Stack<Stack<T>> stacks;
    
    public:
        template <typename U>
        void push( U&& data );
        T& peek() { return stacks.peek().peek(); }
        T  pop ();
        size_t size() const { return stacks.size(); }
        void print();
};


template <typename T, size_t Capacity>
template <typename U>
void SetOfStacks<T, Capacity>::push( U&& data )
{
    if( stacks.isEmpty() || stacks.peek().size() >= Capacity ){
        stacks.push( Stack<T>() );
    }
    stacks.peek().push( forward<U>(data) );
}

template <typename T, size_t Capacity>
T SetOfStacks<T, Capacity>::pop()
{
    T value = stacks.peek().pop();
    if( stacks.peek().isEmpty() ) stacks.pop();
    return value;
}

template <typename T, size_t Capacity>
void SetOfStacks<T, Capacity>::print()
{
    stacks.peek().print();
}

// If Capacity is 1 we do not need stack of stacks.
template <typename T>
class SetOfStacks<T, 1> : public Stack<T>
{
};

// Forbid Capacity 0
template <typename T>
class SetOfStacks<T, 0>
{
    public:
        SetOfStacks() = delete;
};



int main()
{
    mt19937 mt(1);
    uniform_int_distribution<> rand(0,10);

    SetOfStacks<int, 3> S;
    for( int i = 0; i < 9; ++i ) S.push( rand(mt) );
    
    cout << S.size() << endl;
    S.print();
}