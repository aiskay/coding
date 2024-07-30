#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

void calcDist(int pos, int d, vector<int>& dist, vector<vector<int>>& G)
{
    if(dist[pos] >= 0) return;
    dist[pos] = d;
    for(auto v: G[pos]) calcDist(v, d+1, dist, G);
}

int dfs(int ans, int pos, vector<int>& dist_from_u, vector<int>& dist_from_v, vector<bool>& visited, vector<vector<int>>& G)
{
    if(visited[pos]) return ans;

    visited[pos] = true;
    for(auto v: G[pos]) ans = max(ans, dfs(ans, v, dist_from_u, dist_from_v, visited, G));

    if(dist_from_u[pos] < dist_from_v[pos]) return max(ans, dist_from_v[pos]-1);
    else return ans;
}


int main()
{
    int N, u, v;
    cin >> N >> u >> v;
    --u, --v;
    vector<vector<int>> G(N);
    REP(i, N-1){
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<int> dist_from_u(N, -1), dist_from_v(N, -1);
    calcDist(u, 0, dist_from_u, G);
    calcDist(v, 0, dist_from_v, G);
    
    vector<bool> visited(N, false);
    cout << dfs(0, v, dist_from_u, dist_from_v, visited, G) << endl;

    return 0;
}