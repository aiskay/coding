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
    else return gcd<T>(b, a % b);
}

// Least Common Multiple (LCM)
// 2数の最小公倍数
template <typename T=long long>
T lcm(T a, T b) {return a * b / gcd<T>( a, b );}

int main()
{
    long long N, M;
    cin >> N >> M;
    vector<long long> a(N);
    REP(i, N) cin >> a[i];

    long long LCM = 1;
    int prev_count = -1;
    REP(i, N){
        a[i] = a[i]/2;
        LCM = lcm<long long>(LCM, a[i]);
        // 2で割れる回数は同じじゃないとダメ
        int count = 0;
        while(a[i]%2 == 0){
            a[i] /= 2;
            ++count;
        }
        if(prev_count == -1) prev_count = count;
        if(prev_count != count or LCM > M){
            cout << 0 << endl;
            return 0;
        }
        prev_count = count;
    }
    cout << (M/LCM+1)/2 << endl;

    return 0;
}