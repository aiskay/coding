#include <iostream>
#include <vector>
using namespace std;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0, pos = -1;
    for(int i = 0; ((long long) 1<<i) <= N; ++i){
        if(N & (1<<i)){
            if(pos != -1) ans = max(ans, i-pos-1);
            pos = i;
        }
    }
    return ans;
}


int main(){
    int N;
    cin >> N;

    cout << solution(N) << endl;

    return 0;
}