#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int INF = 1e+9;


void dfs(int curr_pos, int curr_d, vector<int>& d, vector<vector<int>>& G)
{
    if(d[curr_pos] < curr_d) return;
    d[curr_pos] = curr_d;
    for(auto v: G[curr_pos]) dfs(v, curr_d+1, d, G);
}


int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    --X, --Y;

    // Create the Graph
    vector<vector<int>> G(N);
    REP(i, N-1){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[X].push_back(Y);
    G[Y].push_back(X);

    // Calculate the distance
    vector<vector<int>> d(N, vector<int>(N, INF));
    REP(i, N) dfs(i, 0, d[i], G);

    // Count the number
    vector<int> ans(N);
    REP(i, N){
        FOR(j, i+1, N) ++ans[d[i][j]];
    }
    FOR(i, 1, N) cout << ans[i] << endl;

    return 0;
}