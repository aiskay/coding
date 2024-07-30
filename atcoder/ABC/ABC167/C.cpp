#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(M));
    REP(i, N){
        cin >> C[i];
        REP(j, M) cin >> A[i][j];
    }

    int ans = 1e+9;
    // 全探索 by bit
    for(int i = 0; i < (1 << N); ++i){
        int cost = 0;
        vector<int> understand(M, 0);
        for(int j = 0; j < N; ++j){
            if(i & (1<<j)){
                cost += C[j];
                REP(k, M) understand[k] += A[j][k];
            }
        }
        bool is_understand = true;
        REP(k, M){
            if(understand[k] < X){
                is_understand = false;
                break;
            }
        }
        if(is_understand) ans = min(ans, cost);
    }
    if(ans == 1e+9) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}