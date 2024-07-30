#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 998244353;

template <typename T=long long>
T pow_mod(T n, T p, T m)
{
    if(p == 0) return 1;
    if(p%2 == 1) return pow_mod<T>(n, p-1, m) * n % m;
    else{
        T tmp = pow_mod<T>(n, p/2, m) % m;
        return tmp * tmp % m;
    }
}

int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    REP(i, N) cin >> A[i];


    // i まで見て j になる組み合わせの数
    vector<vector<long long>> dp(N+1, vector<long long>(S+1, 0));
    dp[0][0] = 1;
    FOR(i, 1, N+1){
        REP(j, S+1){ 
            dp[i][j] = dp[i-1][j];
            if(j >= A[i-1]) dp[i][j] += dp[i-1][j-A[i-1]];
            dp[i][j] %= MOD;
        }
    }

    // 後ろから i まで見て j個で S になるような組み合わせの個数
    vector<long long> comb(N+1);
    comb[N] = dp[N][S];
    for(int i = N; i >= 1; --i){
        REP(j, N+1){
            comb[j+1] += dp[i][j-A[i-1]];
        }
    }

    long long ans = 0;
    REP(i, N){
        ans += comb[0][i]*pow_mod<long long>(2, N-(i+1), MOD) % MOD;
        ans %= MOD;
    }   
    cout << ans << endl;

    return 0;
}