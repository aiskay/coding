#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int R, C, K;
    cin >> R >> C >> K;
    vector<vector<long long>> matrix(R, vector<long long>(C, 0));
    REP(i, K){
        int r, c, v;
        cin >> r >> c >> v;
        r--, c--;
        matrix[r][c] = v;
    }

    vector<vector<long long>> dp(R, vector<long long>(C, 0));
    REP(i, R){
        priority_queue<long long> q;
        REP(j, C){
            q.push(matrix[i][j]);
            vector<long long> tmp;
            REP(k, 3){
                if(q.empty()) break;
                tmp.push_back(q.top());
                q.pop();
            }
            if(i > 0) dp[i][j] = max(dp[iaccumulate(tmp.begin(), tmp.end(), (long long)0), dp[i-1][j]);
            else dp[i][j] = accumulate(tmp.begin(), tmp.end(), (long long)0);
            for(auto t: tmp) q.push(t);
        }
    }
    long long ans = 0;
    REP(i, R){
        REP(j, C) ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;

    return 0;
}