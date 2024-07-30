#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 998244353;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> L(K), R(K);
    REP(i, K) cin >> L[i] >> R[i];

    // dp[i][j] = j を使って i まで行く方法の個数
    vector<long long> dp(N+1, 0);
    dp[1] = 1;
    FOR(i, 2, N+1){
        REP(j, K){
            if(0 <= i-L[j]){
                dp[i] += dp[i-L[j]];
                dp[i] %= MOD;
            }
            if(0 <= i-R[j]-1){
                dp[i] -= dp[i-R[j]-1];
                dp[i] %= MOD;
            }
        }
        if(i < N) dp[i] += dp[i-1];
    }
    cout << (dp[N]+MOD)%MOD << endl;

    return 0;
}