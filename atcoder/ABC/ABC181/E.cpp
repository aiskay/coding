#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, M;
    cin >> N >> M;
    vector<long long> H(N), W(M);
    REP(i, N) cin >> H[i];
    REP(i, M) cin >> W[i];

    sort(H.begin(), H.end());

    vector<long long> diff(N);
    REP(i, N-1) diff[i] = H[i+1]-H[i];

    vector<long long> rl(diff), lr(diff);
    REP(i, N-2) lr[i+1] += lr[i];
    for(int i = N-1; i > 0; --i) rl[i-1] += rl[i];

    REP(i, N) cout << lr[i] << " " << rl[i] << endl;

    long long ans = 1e+18;
    REP(i, M){
        int idx = distance(H.begin(), upper_bound(H.begin(), H.end(), W[i]));
        if(idx == 0) ans = min(ans, rl[idx+1] + abs(W[i]-H[idx]));
        else if(idx == 1) ans = min(ans, rl[idx] + abs(W[i]-H[idx-1]));
        else if(idx == N) ans = min(ans, lr[idx-3] + abs(W[i]-H[idx-1]));
        else if(idx == N-1) ans = min(ans, lr[idx-2] + abs(W[i]-H[idx]));
        else if(idx%2 == 0){  // 後ろと結合
            ans = min(ans, lr[idx-2]+rl[idx] + abs(W[i]-H[idx]));
        }else{  // 前と結合
            ans = min(ans, lr[idx-2]+rl[idx] + abs(W[i]-H[idx-1]));
        }
        cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}