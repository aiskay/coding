#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

constexpr int MOD = 1e+9 + 7;

// Greatest Common Multiple (GCD)
// 2数の最大公約数 by ユークリッド互助法
template <typename T>
T gcd(T a, T b)
{
    if(b == 0) return a;
    else return gcd<T>(b, a % b);
}

// 繰り返し二乗法(Exponentiation by squaring)
// n^8 = ((n^2)^2)^2 を利用する
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
    map<pair<long long,long long>, pair<int,int>> P;
    int num_zeros = 0;
    REP(i, N){
        long long A, B;
        cin >> A >> B;
        if(A == 0 and B == 0){ // (0, 0) は全てのイワシと仲が悪い
            ++num_zeros;  
            continue;
        }
        // A/B の組を記録
        long long GCD = gcd<long long>(A, B);  // (正, 負) の gcd は負になるので注意
        A /= GCD;
        B /= GCD;
        if(B < 0){  // A < 0 となるようにする
            A = -A;  
            B = -B;
        }
        // A の正負で first, second を分類
        if(A > 0) P[make_pair(A, B)].first++;
        else P[make_pair(B, -A)].second++;
    }

    long long ans = 1;
    for(auto p: P){
        int num_i = p.second.first;
        int num_j = p.second.second;
        long long num_pairs = pow_mod<long long>(2, num_i, MOD) + pow_mod<long long>(2, num_j, MOD) - 1;
        ans *= num_pairs%MOD;
        ans %= MOD;
    }
    cout << (ans+num_zeros-1+MOD)%MOD << endl;

    return 0;
}