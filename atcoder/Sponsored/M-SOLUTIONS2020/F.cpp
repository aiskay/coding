#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

struct plain{
    int x, y;
    plain(int x, int y): x(x), y(y) {}
};

int main()
{
    int N;
    cin >> N;
    vector<plain> pu, pd, pr, pl;
    REP(i, N){
        int x, y;
        char U;
        cin >> x >> y >> U;
        if(U == 'U') pu.emplace_back(plain(x,y));
        if(U == 'D') pd.emplace_back(plain(x,y));
        if(U == 'R') pr.emplace_back(plain(x,y));
        if(U == 'L') pl.emplace_back(plain(x,y));
    }

    int ans = 1e+9;
    // y方向からぶつかるもの -> x座標が同じもの
    sort(pu.begin(), pu.end());
    sort(pd.begin(), pd.end());
    


    int j1 = 1, j2 = 1, j3 = 1;
    // x方向からぶつかるもの
    REP(i, N){
        // x+y が同じもの -> 'D'かつ'L' or 'U'かつ'R'
        auto itr = lower_bound()

        // x-y が同じもの -> 'D'かつ'R' or 'U'かつ'L'


    }

    if(ans == 1e+9) cout << "SAFE" << endl;
    else cout << ans << endl;

    return 0;
}