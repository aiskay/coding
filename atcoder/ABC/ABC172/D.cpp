#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;

    vector<int> f(N+1, 1);
    FOR(i, 2, N+1){
        for(long long j = 1; i*j <= N; ++j) ++f[i*j];
    }

    long long ans = 0;
    FOR(K, 1, N+1) ans += (long long) K*f[K];
    cout << ans << endl;

    return 0;
}