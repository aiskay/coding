#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    int ans = 0;
    // (i, j) からいける場所の最短経路の最長距離を求める
    REP(i, H){
        REP(j, W){
            if(S[i][j] == '#') continue;

            vector<vector<int>> dist(H, vector<int>(W, 1e+3));
            dist[i][j] = 0;

            queue<pair<int,int>> q;
            q.push({i, j});

            while(!q.empty()){
                auto tmp = q.front();
                q.pop();
                int x = tmp.first;
                int y = tmp.second;
                vector<pair<int,int>> next = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for(auto n: next){
                    int nx = x+n.first;
                    int ny = y+n.second;
                    if(0 <= nx and nx < H and 0 <= ny and ny < W and S[nx][ny] == '.'){
                        if(dist[nx][ny] > dist[x][y]+1){
                            dist[nx][ny] = dist[x][y]+1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            REP(k, H){
                REP(l, W){
                    if(dist[k][l] != 1e+3) ans = max(ans, dist[k][l]);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}