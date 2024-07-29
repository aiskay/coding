#include <climits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = INT_MAX;
    for(int i = 1; (long long) i*i <= N; ++i){
        if(N%i == 0) ans = min(ans, 2*(i + N/i));
    }

    return ans;
}