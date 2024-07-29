#include <iostream>
#include <vector>
using namespace std;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    if(N == 0) return vector<int>(0);
    K %= N;
    vector<int> ret(N);
    for(int i = 0; i < N; ++i){
        if(i < K) ret[i] = A[N-K+i];
        else ret[i] = A[i-K];
    }
    return ret;
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    A = solution(A, K);
    for(auto& a: A) cout << a << " ";
    cout << endl;
}

