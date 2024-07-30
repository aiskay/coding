#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 998244353;

template <typename T>
T pow_mod(T n, T p, T m)  // (n^p) % m
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
    int N, M, K;
    cin >> N >> M >> K;

    // M == 1 の場合、下で factor = 0 となって答えが 0 になるが、N == 1 or K == N-1 のときのみ違う
    if(M == 1 and (N == 1 or K == N-1)){
        cout << 1 << endl;
        return 0;
    }

    vector<long long> comb(K+1, 0);
    comb[0] = 1;
    FOR(i, 1, K+1){
        comb[i] = ((N-i)*comb[i-1])%MOD * pow_mod<long long>(i, MOD-2, MOD);
        comb[i] %= MOD;
    }

    long long ans = 0, factor = pow_mod<long long>(M-1, N-1, MOD);
    REP(k, K+1){
        ans += ((M*factor)%MOD*comb[k]) % MOD;
        ans %= MOD;
        factor *= pow_mod<long long>(M-1, MOD-2, MOD);
        factor %= MOD;
    }
    cout << ans << endl;

    return 0;
}