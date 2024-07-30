#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int solution(int N, int H, vector<int>& A, vector<int>& B)
{
    vector<vector<int>> dp(N+1, vector<int>(H+1, 1e+9));
    dp[0][H] = 0;
    for(int i = 0; i < N; ++i){
        for(int h = 0; h <= H; ++h) dp[i+1][h] = dp[i][h];
        for(int h = H; h >= 0; --h){
            dp[i+1][h] = min(dp[i+1][h], dp[i+1][min(H, h+A[i])]+B[i]);
        }
    }
    return dp[N][0];
}

int main()
{
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];

    // dp[i][j] = i まで見て体力を j にするのに必要な最小のコスト
    vector<vector<int>> dp(N+1, vector<int>(H+1, 1e+9));
    dp[0][0] = 0;
    REP(i, N){
        REP(h, H+1) dp[i+1][h] = dp[i][h];
        REP(h, H+1){
            dp[i+1][h] = min(dp[i+1][h], dp[i+1][max(0, h-A[i])]+B[i]);
        }
    }
    // cout << dp[N][H] << endl;
    cout << solution(N, H, A, B) << endl;

    return 0;
}