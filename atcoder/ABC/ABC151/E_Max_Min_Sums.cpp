#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

// MOD を取りながら nCm を計算する方法
// フェルマーの小定理を使って逆元を使う
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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    vector<long long> iCK(N+1, 0);
    REP(i, N+1){
        if(i == K) iCK[i] = 1;
        if(i > K){
            iCK[i] = (i*iCK[i-1]) % MOD * pow_mod<long long>(i-K, MOD-2, MOD);
            iCK[i] %= MOD;
        }
    }

    sort(A.begin(), A.end());
    long long ans = 0;
    REP(i, N-K+1){
        ans -= (long long) A[i] * (iCK[N-i] - iCK[N-i-1]);
        ans %= MOD;
    }
    FOR(i, K-1, N){
        ans += (long long) A[i] * (iCK[i+1] - iCK[i]);
        ans %= MOD;
    }
    cout << (ans+MOD)%MOD << endl;

    return 0;
}