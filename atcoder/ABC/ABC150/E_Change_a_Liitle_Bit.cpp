#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

template <typename T>
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
    int N;
    cin >> N;
    vector<long long> C(N);
    REP(i, N) cin >> C[i];

    sort(C.begin(), C.end());  // コストの小さい順に変更していくのが最適

    long long ans = 0, before_cases = 1;  // (S[:i], T[:i]) のありうる場合の数
    REP(i, N){
        long long in_cases = pow_mod<long long>(2, 2*N-2*i-2, MOD) * (N-i+1) % MOD;
        ans += before_cases * C[i] % MOD * in_cases % MOD;
        ans %= MOD;
        before_cases *= 4;
        before_cases %= MOD;
    }    
    cout << ans << endl;

    return 0;
}