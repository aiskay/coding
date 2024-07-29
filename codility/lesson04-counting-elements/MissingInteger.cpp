// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int A_max = 1e+6;
    vector<bool> is_appeared(A_max+2, false);
    for(auto a: A){
        if(a <= 0) continue;
        else is_appeared[a] = true;
    }

    for(int i = 1; i <= A_max+1; ++i){
        if(!is_appeared[i]) return i;
    }
}