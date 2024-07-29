// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> cum_num_west(A);
    long long ans = 0;
    for(int i = A.size()-2; i >= 0; --i){
        cum_num_west[i] += cum_num_west[i+1];
        if(A[i] == 0) ans += cum_num_west[i];
    }
    if(ans > 1e+9) return -1;
    else return ans;
}