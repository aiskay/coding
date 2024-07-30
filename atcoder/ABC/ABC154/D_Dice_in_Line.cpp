#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> p(N+1, 0);
    FOR(i, 1, N+1) cin >> p[i];

    // 累積和
    FOR(i, 1, N+1) p[i] += p[i-1]+1;

    double ans = 0;
    REP(i, N-K+1) ans = max(ans, (p[i+K]-p[i])/2.0);
    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}