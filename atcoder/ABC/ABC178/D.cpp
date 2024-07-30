#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

int main()
{
    int S;
    cin >> S;

    // dp[i][j] = 数列の長さが i で和が j であるものの個数
    long long ans = 0;
    vector<vector<long long>> dp(S, vector<long long>(S+1, 0));
    dp[0][0] = 1;
    REP(i, S-1){
        ans += dp[i][S];
        ans %= MOD;
        // 累積和
        FOR(j, 1, S+1){
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
        FOR(j, 3, S+1) dp[i+1][j] = dp[i][j-3];
    }
    cout << ans << endl;

    return 0;
}