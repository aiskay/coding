#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


const int MOD = 1e+9 + 7;

template <typename T>
T pow_mod( T n, T p, T m )
{
    if( p == 0 ) return 1;
    if( p%2 == 1 ) return pow_mod(n, p-1, m) * n % m;
    else{
        T tmp = pow_mod(n, p/2, m) % m;
        return tmp * tmp % m;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    long long ans = 0;
    vector<long long> num_cases(K+1);
    // gcd が i になるものの個数を求める
    for(int i = K; i >= 1; --i){
        num_cases[i] = pow_mod<long long>(K/i, N, MOD);
        int j = 2;
        while(i*j <= K) num_cases[i] -= num_cases[i*j++];
        ans += (i * num_cases[i]) % MOD;
    }
    cout << ans % MOD << endl;

    return 0;
}