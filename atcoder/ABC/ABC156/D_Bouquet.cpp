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
    if( p == 0 ) return 1;
    if( p%2 == 1 ) return pow_mod<T>(n, p-1, m) * n % m;
    else{
        T tmp = pow_mod<T>(n, p/2, m) % m;
        return tmp * tmp % m;
    }
}

template <typename T=long long>
T nCk_mod(T n, T k, T m)
{
    if( n < 0 or k < 0 || n < k ) return 0;
    T numerator = 1, denominator = 1;
    for(int i = 1; i <= min(k, n-k); ++i){
        numerator = numerator*(n-i+1) % m;
        denominator = denominator*i % m;
    }
    return numerator * pow_mod<T>(denominator, m-2, m) % m;
}


int main()
{
    long long n, a, b;
    cin >> n >> a >> b;

    long long ans = pow_mod<long long>(2, n, MOD) - 1;
    ans -= nCk_mod<long long>(n, a, MOD) + nCk_mod<long long>(n, b, MOD);
    cout << (ans+2*MOD)%MOD << endl;

    return 0;
}