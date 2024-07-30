#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


stack<pair<int,int>> s;

void dfs(int pos, vector<vector<int>>& G, vector<int>& a, vector<int>& dp, vector<int>& ans, vector<bool>& is_visited){
    is_visited[pos] = true;
    int insert_pos = distance(dp.begin(), lower_bound(dp.begin(), dp.end(), a[pos]));
    int old = dp[insert_pos];
    dp[insert_pos] = a[pos];
    ans[pos] = distance(dp.begin(), lower_bound(dp.begin(), dp.end(), 1e+9));
    for(auto e: G[pos]){
        if(is_visited[e]) continue;
        dfs(e, G, a, dp, ans, is_visited);
    }
    dp[insert_pos] = old;
}


int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    vector<vector<int>> G(N);
    REP(i, N-1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> ans(N), dp(N, 1e+9);
    vector<bool> is_visited(N, false);
    dfs(0, G, a, dp, ans, is_visited);
    REP(i, N) cout << ans[i] << endl;

    return 0;
}