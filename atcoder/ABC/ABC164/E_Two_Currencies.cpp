#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

struct edge
{
    int to;
    int change;
    int time;
    edge(int to, int c, int t): to(to), change(c), time(t) {}

};

struct data_t
{
    int v;       // 今の頂点
    int change;  // 今の銀貨の枚数
    long long time;    // 今のかかった時間

    data_t(int v, int change, long long time): v(v), change(change), time(time) {}

    bool operator < (const data_t& right) const {
        return time > right.time;
    }
};

int main()
{
    int N, M, S;
    cin >> N >> M >> S;
    vector<vector<edge>> G(N);
    REP(i, M){
        int U, V, A, B;
        cin >> U >> V >> A >> B;
        --U, --V;
        G[U].emplace_back(V, A, B);
        G[V].emplace_back(U, A, B);
    }
    vector<int> C(N), D(N);
    REP(i, N) cin >> C[i] >> D[i];


    int mx = 50*(N-1);  // 高々 50*(N-1) 枚の銀貨があれば十分

    // dp[i][j] = i まで銀貨 j 枚で行ける最短の時間
    vector<vector<long long>> dp(N, vector<long long>(mx+1, 1e+18));
    priority_queue<data_t> q;
    q.emplace(0, min(S, mx), 0);
    while(!q.empty()){
        auto top = q.top(); q.pop();
        int v = top.v;
        int c = top.change;
        long long t = top.time;
        if(c < 0 or dp[v][c] <= t) continue;
        dp[v][c] = t;
        q.emplace(v, min(c+C[v], mx), t+D[v]);
        for(auto e: G[v]){
            q.emplace(e.to, min(c-e.change, mx), t+e.time);
        }
        // cout << v << " " << c << " " << t << " " <<  endl;
    }

    FOR(i, 1, N) cout << *min_element(dp[i].begin(), dp[i].end()) << endl;

    return 0;
}