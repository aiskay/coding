#include <iostream>
#include <vector>
// you can use includes, for example:
// #include <algorithm>
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int first = 0, second = accumulate(A.begin(), A.end(), 0);
    int ans = 1e+9;
    for(int i = 1 ; i < N; ++i){
        first += A[i-1];
        second -= A[i-1];
        ans = min(ans, abs(first-second));
    }
    return ans;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();

    for(int i = 0; i < N-1; ++i) A[i+1] += A[i];

    int ans = 1e+9;
    for(int i = 0; i < N-1; ++i){
        ans = min(ans, abs(A[i] - (A[N-1]-A[i])));
    }

    return ans;
}