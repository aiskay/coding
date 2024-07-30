#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;


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
class Combination 
{
    private:
        T _mod;
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
};


int main()
{
    long long n, k;
    cin >> n >> k;

    Combination<long long> comb(n, MOD);
    
    long long ans = 0;
    FOR(i, 0, min(n, k+1)){
        ans += (comb(n,i)*comb(n-1, n-i-1)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}