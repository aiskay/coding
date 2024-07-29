#include <iostream>
#include <vector>
// you can use includes, for example:
// #include <algorithm>
#include <set>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> s;
    for(int i = 1; i <= X; ++i) s.insert(i);
    for(int i = 0; i < (int) A.size(); ++i){
        s.erase(A[i]);
        if((int) s.size() == 0) return i;
    }
    return -1;
}


int main(){
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    cout << solution(X, A) << endl;
}