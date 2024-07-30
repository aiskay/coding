#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int INF = 1e+9 + 10;

/*
int rec(int S, int j, vector<vector<int>>& dp, vector<int>& X, vector<int>& Y, vector<int>& Z)
{
    if(dp[S][j] != -1) return dp[S][j];
    if(S == 1<<j) return dp[S][j] == 0;

    int res = INF;
    int prev_set = S & ~(1<<j);

    REP(u, X.size()){
        if(!(prev_set & (1<<u))) continue;
        res = min(res, rec(prev_set, u, dp, X, Y, Z)+abs(X[j]-X[u])+abs(Y[j]-Y[u])+max(0, Z[j]-Z[u]));
    }

    return dp[S][j] = res;
}
*/

int main()
{
    int N;
    cin >> N;
    vector<int> X(N), Y(N), Z(N);
    REP(i, N) cin >> X[i] >> Y[i] >> Z[i];

    // i -> j の距離
    auto dist = [&](int i, int j){
        return abs(X[j]-X[i])+abs(Y[j]-Y[i])+max(0, Z[j]-Z[i]);
    };

    // dp[S][j] = 部分集合 S を最後が j のときに回るのに必要な最小のコスト
    vector<vector<int>> dp(1<<N, vector<int>(N, INF));
    FOR(i, 1, N) dp[1<<i][i] = dist(0, i);

    REP(S, 1<<N){
        // j -> k のときの最小距離を探索
        REP(j, N){
            if(~S>>j&1) continue;
            REP(k, N){
                if(S>>k&1) continue;
                dp[S|1<<k][k] = min(dp[S|1<<k][k], dp[S][j]+dist(j, k));
            }
        }
    }
    cout << dp[(1<<N)-1][0] << endl;

    return 0;
}