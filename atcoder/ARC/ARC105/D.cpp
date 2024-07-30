#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, M;
    cin >> N >> M;
    vector<long long> w(N), l(M), b(M);
    REP(i, N) cin >> w[i];
    REP(i, M) cin >> l[i] >> b[i];

    // dp[i][j] = i のラクダで橋 j までを渡るときの最短の距離
    vector<vector<long long>> dp(2<<N, vector<long long>(M, 1e+9));
    REP(i, 2<<N){
        REP(j, M){

        }
    }
    cout << dp[2<<N-1][M-1] << endl;

    return 0;
}