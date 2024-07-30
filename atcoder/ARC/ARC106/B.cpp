#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, M;
    cin >> N >> M;
    vector<long long> a(N), b(N);
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];
    vector<vector<int>> G(N);
    REP(i, M){
        int c, d;
        cin >> c >> d;
        --c, --d;
        G[c].push_back(d);
        G[d].push_back(c);
    }

    vector<bool> visited(N, false);
    REP(i, N){
        long long sum_a = 0, sum_b = 0;
        queue<long long> q;
        q.push(i);
        while(!q.empty()){
            int tmp = q.front(); q.pop();
            if(visited[tmp]) continue;
            visited[tmp] = true;
            sum_a += a[tmp];
            sum_b += b[tmp];
            for(auto v: G[tmp]) q.push(v);
        }
        if(sum_a != sum_b){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}