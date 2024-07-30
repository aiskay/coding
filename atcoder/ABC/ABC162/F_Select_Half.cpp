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
    vector<long long> A(N);
    REP(i, N) cin >> A[i];

    // dp[i][j] = i 番目を選んで飛ばした個数が j のときの最大値
    vector<vector<long long>> dp(N, vector<long long>(3, -1e+18));
    dp[0][0] = A[0];
    dp[1][1] = A[1];
    if(N%2 == 1) dp[2][2] = A[2];
    REP(i, N){
        if(i >= 2) dp[i][0] = dp[i-2][0] + A[i];
        if(i >= 3) dp[i][1] = max(dp[i-2][1], dp[i-3][0]) + A[i];
        if(N%2 == 1 and i >= 4) dp[i][2] = max({dp[i-2][2], dp[i-3][1], dp[i-4][0]}) + A[i];
    }
    if(N%2 == 0) cout << max(dp[N-2][0], dp[N-1][1]) << endl;
    if(N%2 == 1) cout << max({dp[N-3][0], dp[N-2][1], dp[N-1][2]}) << endl;

    return 0;
}