#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

int main()
{
    int N, K;
    cin >> N >> K;
    
    // i 個選ぶとき
    long long ans = 0;
    FOR(i, K, N+2){
        ans += (long long) (2*N-i+1)*i/2 - (long long) i*(i-1)/2 + 1;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}