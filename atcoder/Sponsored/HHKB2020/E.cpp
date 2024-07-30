#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

template <typename T=long long>
T pow_mod(T n, T p, T m)
{
    T r = 1;
    // p の下の桁から処理していく
    for( ; p > 0; p >>= 1 ){
        if(p & 1) r = (r * n) % m;  // p の1bit目が立っていれば r に n^? を掛ける
        n = (n * n) % m;              // 次の処理に向けて n を2乗しておく
    }
    return r;
}


int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    int K = 0;
    vector<vector<int>> num_row(H, vector<int>(W, 0)), num_col(H, vector<int>(W, 0));
    REP(i, H){
        REP(j, W){
            if(S[i][j] == '.'){
                if(j > 0) num_row[i][j] = num_row[i][j-1];
                ++num_row[i][j];
                ++K;
            }
        }
        int now = num_row[i][W-1];
        for(int j = W-2; j >= 0; --j){
            if(S[i][j] == '#') now = 0;
            else if(now > num_row[i][j]) num_row[i][j] = now;
            else now = num_row[i][j];
        }
    }
    REP(j, W){
        REP(i, H){
            if(S[i][j] == '.'){
                if(i > 0) num_col[i][j] = num_col[i-1][j];
                ++num_col[i][j];
            }
        }
        int now = num_col[H-1][j];
        for(int i = H-2; i >= 0; --i){
            if(S[i][j] == '#') now = 0;
            else if(now > num_col[i][j]) num_col[i][j] = now;
            else now = num_col[i][j];
        }
    }

    /*
    REP(i, H){
        REP(j, W) cout << num_row[i][j];
        cout << endl;
    }
    cout << endl;
    REP(i, H){
        REP(j, W) cout << num_col[i][j];
        cout << endl;
    }
    */

    // マスに注目して何回照らされるか数える
    long long ans = 0;
    REP(i, H){
        REP(j, W){
            if(S[i][j] == '.'){
                ans += (pow_mod<long long>(2, num_row[i][j]+num_col[i][j]-1, MOD)-1) * pow_mod<long long>(2, K-num_row[i][j]-num_col[i][j]+1, MOD) % MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;

    return 0;
}