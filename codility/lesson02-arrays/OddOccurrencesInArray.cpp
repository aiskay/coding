#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, int> m;
    for(auto a: A){
        if(m.find(a) != m.end()) ++m[a];
        else m[a] = 1;
    }
    for(auto e: m){
        if(e.second%2 == 1) return e.first;
    }
}


int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    cout << solution(A) << endl;
}
