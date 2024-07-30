#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


// Greatest Common Multiple (GCD)
// 2数の最大公約数 by ユークリッド互助法
template <typename T=long long>
T gcd(T a, T b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

// 3数以上の最大公約数
// a, b, c の最小公約数は a, b の最小公約数と c の最小公約数に等しいことを利用
template <typename T=long long>
T gcd(std::vector<T>& a, int i = 0)  // a[i] と a[i+1] ~ a[end] の最大公約数を返す
{
    if( a.size() < 2 ) return 0;  // 必要に応じて変える
    if( i == (int) a.size() - 2 ) return gcd( a[i], a[i+1] );
    return gcd( a[i], gcd(a, i+1) );
}

int main()
{
    int K;
    cin >> K;

    long long ans = 0;
    FOR(a, 1, K+1){
        FOR(b, 1, K+1){
            FOR(c, 1, K+1){
                vector<long long> x = {a, b, c};
                ans += gcd(x);
            }
        }
    }
    cout << ans << endl;

    return 0;
}