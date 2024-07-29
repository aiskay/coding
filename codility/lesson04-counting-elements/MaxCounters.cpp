// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_count = 0, next_max_count = 0;
    vector<int> ans(N, 0);
    for(int i = 0; i < (int) A.size(); ++i){
        if(A[i] <= N){
            ans[A[i]-1] = max(max_count, ans[A[i]-1]) + 1;
            next_max_count = max(next_max_count, ans[A[i]-1]);
        }else{
            max_count = max(max_count, next_max_count);
        }
    }

    for(auto& a: ans) a = max(a, max_count);

    return ans;
}