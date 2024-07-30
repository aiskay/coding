#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    vector<int> P(N*N);
    REP(i, N*N) cin >> P[i];

    vector<vector<int>> num_pairs(N, vector<int>(N));
    REP(i, N){
        REP(j, N) num_pairs[i][j] = min({i, j, N-i-1, N-j-1});
    }

    int ans = 0;
    vector<vector<bool>> is_empty(N, vector<bool>(N, false));
    REP(n, N*N){
        int i = (P[n]-1)/N;
        int j = (P[n]-1)%N;
        ans += num_pairs[i][j];
        is_empty[i][j] = true;

        //
        queue<pair<int,int>> q;
        q.push({i, j});
        while(!q.empty()){
            auto top = q.front(); q.pop();
            i = top.first;
            j = top.second;
            vector<int> di = {1, 0, -1, 0};
            vector<int> dj = {0, 1, 0, -1};
            REP(k, 4){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(0 <= ni and ni < N and 0 <= nj and nj < N){
                    int cand = num_pairs[i][j] + !is_empty[i][j];
                    if(num_pairs[ni][nj] > cand){
                        num_pairs[ni][nj] = cand;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}