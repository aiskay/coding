#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long N, K;
    cin >> N >> K;

    // a+b == S となる数
    vector<long long> num(2*N+1);
    int tmp = 1;
    FOR(S, 2, 2*N+1){
        num[S] = tmp;
        if(S < N+1) ++tmp;
        else --tmp;
    }

    // REP(i, 2*N+1) cout << num[i] << " ";
    // cout << endl;

    long long ans = 0;
    FOR(S, 2, 2*N+1){
        if(2 <= S-K and S-K <= 2*N) ans += num[S]*num[S-K];
    }
    cout << ans << endl;

    return 0;
}