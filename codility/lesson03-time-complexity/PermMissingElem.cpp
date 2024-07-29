#include <vector>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    vector<bool> is_exist(N+1, false);
    for(auto a: A) is_exist[a-1] = true;
    for(int i = 0; i < N+1; ++i){
        if(!is_exist[i]) return i+1;
    }
}