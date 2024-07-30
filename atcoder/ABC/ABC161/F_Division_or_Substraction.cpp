#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long N;
    cin >> N;

    // N と N-1 の約数について調べる
    int ans = (N == 2)? 1: 2;  // K = N, N-1 の分

    // N について
    // N の約数は小さい方だけ考えれば良い N = x*y (x < y) のとき、N/y = x < y だから
    for(long long i = 2; i*i <= N; ++i){
        long long tmp = N;
        if(tmp%i == 0){
            while(tmp%i == 0) tmp /= i;
            if(tmp%i == 1) ++ans;
        }
    }

    // N-1 について
    // N-1 の約数は全部OK
    for(long long i = 2; i*i<= N-1; ++i){
        if((N-1)%i == 0){
            ++ans;  // 約数のうち小さい方
            if(i*i != N-1) ++ans;  // 約数のうち大きい方
        } 
    }
    cout << ans << endl;

    return 0;
}