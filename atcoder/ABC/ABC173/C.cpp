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
    vector<string> c(H);
    REP(i, H) cin >> c[i];

    int ans = 0;
    for(int i = 0; i < (1<<H); ++i){
        for(int j = 0; j < (1<<W); ++j){
            int num = 0;
            REP(k, H){
                REP(l, W){
                    if(c[k][l] == '#' and !(i&(1<<k)) and (j&(1<<l))) ++num;
                }
            }
            if(num == K) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}