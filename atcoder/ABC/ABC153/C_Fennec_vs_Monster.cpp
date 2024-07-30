#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    REP(i, N) cin >> H[i];

    long long ans = 0;
    sort(H.begin(), H.end());
    REP(i, N-K) ans += (long long) H[i];
    cout << ans << endl;

    return 0;
}