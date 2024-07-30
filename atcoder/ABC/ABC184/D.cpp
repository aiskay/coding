#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    // dp[i][j][k] := (i, j, k) から 100 にするのに必要な回数の期待値
    vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101)));

    for(int i = 99; i >= A; --i){
        for(int j = 99; j >= B; --j){
            for(int k = 99; k >= C; --k){
                if(i+1 <= 100) dp[i][j][k] += i * (dp[i+1][j][k]+1)/(i+j+k);
                if(j+1 <= 100) dp[i][j][k] += j * (dp[i][j+1][k]+1)/(i+j+k);
                if(k+1 <= 100) dp[i][j][k] += k * (dp[i][j][k+1]+1)/(i+j+k);
            }
        }
    }
    cout << setprecision(10) << dp[A][B][C] << endl;

    return 0;
}