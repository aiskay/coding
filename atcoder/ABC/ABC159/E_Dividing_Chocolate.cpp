#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    // 2 次元 imos
    vector<vector<int>> num_white(H+1, vector<int>(W+1));
    REP(i, H){
        REP(j, W){
            if(S[i][j] == '1') ++num_white[i][j];
            num_white[i][j+1] += num_white[i][j];
        }
    }
    REP(i, H){
        REP(j, W) num_white[i+1][j] += num_white[i][j];
    }

    int ans = 1e+7;
    // 横に引く線の位置について全探索
    for(int i = 0; i < (1 << (H-1)); ++i){
        vector<int> pos_hol;
        REP(j, H) if(i & (1<<j)) pos_hol.push_back(j);
        pos_hol.push_back(H-1);

        int num_lines = pos_hol.size()-1;

        int pos_ver = -1; // 縦線の位置
        bool flag = true;
        REP(j, W){
            //左から順に見ていって K を超えたらその手前で線を引く
            REP(k, pos_hol.size()){
                int num = num_white[pos_hol[k]][j];
                if(k > 0) num -= num_white[pos_hol[k-1]][j];
                if(pos_ver >= 0) num -= num_white[pos_hol[k]][pos_ver];
                if(k > 0 and pos_ver >= 0) num += num_white[pos_hol[k-1]][pos_ver];
                if(num > K){
                    pos_ver = j-1;
                    ++num_lines;
                }
                if(j == 0 and num > K){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) ans = min(ans, num_lines);
    }
    cout << ans << endl;

    return 0;
}