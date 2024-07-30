#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

constexpr int MAX = 1e+9;

void dfs(int pos, int par, vector<pair<int,int>>& ans, vector<vector<int>>& G)
{
    ans[pos].first = ans[par].first+1;
    ans[pos].second = par;
    for(auto v: G[pos]){
        if(ans[v].first > ans[pos].first) dfs(v, pos, ans, G);
    }    
}


int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    REP(i, M){ 
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    // (距離, そこに来た親) の順
    vector<pair<int,int>> ans(N, make_pair(MAX, 0));     
    // ans[0].first = 0;
    // dfs(0, 0, ans, G);

    vector<int> d(N, MAX);
    d[0] = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        auto top = q.front(); q.pop();
        int curr = top.first;
        int par = top.second;
        if(curr != 0 and d[curr] != MAX) continue;
        d[curr] = d[par]+1;
        ans[curr].second = par;
        for(auto v: G[curr]){
            if(d[v] == MAX) q.push(make_pair(v, curr));
        }
    }

    cout << "Yes" << endl;
    FOR(i, 1, N) cout << ans[i].second+1 << endl;

    return 0;
}