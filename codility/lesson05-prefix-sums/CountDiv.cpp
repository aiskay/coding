// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int start = (A-1)/K;
    int end = B/K;
    if(A == 0) return end+1;
    else return end-start;
}