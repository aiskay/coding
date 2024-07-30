#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const long long MOD = 998244353;

template <typename T=long long>
T pow_mod2(T n, T p, T m)
{
    T r = 1;
    // p の下の桁から処理していく
    for( ; p > 0; p >>= 1 ){
        if(p & 1) r = (r * n) % m;  // p の1bit目が立っていれば r に n^? を掛ける
        n = (n * n) % m;              // 次の処理に向けて n を2乗しておく
    }
    return r;
}

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;

    cout << A*(A+1)%MOD*pow_mod2<long long>(2, MOD-2, MOD)%MOD
          * B%MOD*(B+1)%MOD*pow_mod2<long long>(2, MOD-2, MOD)%MOD
          * C%MOD*(C+1)%MOD*pow_mod2<long long>(2, MOD-2, MOD)%MOD << endl;

    return 0;
}