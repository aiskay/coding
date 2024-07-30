#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9+7;

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

// nCk を O(n) で求めるクラス
template <typename T>
class Combination { private:
        int _mod;
        std::vector<T> factorial, factorial_inv;

    public:
        Combination(int n, int mod): _mod(mod), factorial(n+1, 1), factorial_inv(n+1)
        {
            for(int i = 1; i <= n; ++i) factorial[i] = (i*factorial[i-1]) % _mod;
            factorial_inv[n] = pow_mod<T>(factorial[n], _mod-2, _mod);  // 逆元を取る操作は重いので一回のみ行う
            for(int i = n; i >= 1; --i) factorial_inv[i-1] = (i*factorial_inv[i]) % _mod;
        } 

        T operator()(int n, int k)
        {
            if(n < 0 or k > n) return 0;
            return factorial[n] * factorial_inv[k] %_mod * factorial_inv[n-k] %_mod;
        }

        T P(int n, int k)
        {
            if(n < 0 or k > n) return 0;
            return factorial[n]*factorial_inv[n-k] % _mod;
        }
};


int main()
{
    long long N, M;
    cin >> N >> M;

    Combination<long long> comb(M, MOD);

    long long ans = 0;
    REP(k, N+1){  // A[i] == B[i] となるものの個数
        long long cases = comb(N, k);
        cases = cases*comb.P(M, k) % MOD;
        cases = cases*comb.P(M-k, N-k) % MOD * comb.P(M-k, N-k) % MOD;
        ans += (k&1)? -cases: cases;
        ans %= MOD;
    }
    cout << (ans+MOD)%MOD << endl;

    return 0;
}