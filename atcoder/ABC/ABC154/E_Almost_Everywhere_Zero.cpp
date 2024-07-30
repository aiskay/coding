#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    string S;
    cin >> S;
    int K;
    cin >> K;

    // dp[i][j][k] = 上から i までみて j 個 non-digit を使ってた時、の場合の数
    int N = S.size();
    vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(K+1, vector<long long>(2, 0)));
    dp[0][0][0] = dp[0][1][1] = 1;
    dp[0][1][0] = S[0]-'1';

    REP(i, N-1){
        REP(j, K+1){
            dp[i+1][j][0] = dp[i][j][0];  // 下で 0 を選んだ場合
            if(j >= 1) dp[i+1][j][0] += 9*dp[i][j-1][0];  // 下で 1~9 を選んだ場合
            if(S[i+1] == '0'){
                dp[i+1][j][1] = dp[i][j][1];  // 最上位を選び続けるやつ
            }else{
                dp[i+1][j][0] += dp[i][j][1];  // 上から 0 を選んでくるやつ
                if(j >= 1){
                    dp[i+1][j][0] += (S[i+1]-'1')*dp[i][j-1][1];  // 上から 0 以外を選んでくるやつ
                    dp[i+1][j][1] = dp[i][j-1][1];  // 最上位を選び続けるやつ
                }
            }
        }
    }
    cout << dp[N-1][K][0] + dp[N-1][K][1] << endl;
    
    return 0;
}