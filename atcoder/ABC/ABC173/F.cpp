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
    vector<vector<int>> G(N);
    REP(i, N-1){
        int u, v;
        cin >> u >> v;
        --u, --vii;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    REP(i, N){
        
    }
    cout << ans << endl;
    

    return 0;
}