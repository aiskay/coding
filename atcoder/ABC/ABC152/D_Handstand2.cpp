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

    // 1 <= k <= N where kの先頭の桁がiに等しく、末尾の桁がjに等しいものの数
    vector<vector<int>> c(10, vector<int>(10));
    FOR(i, 1, N+1){
        string s = to_string(i);
        ++c[s.front()-'0'][s.back()-'0'];
    }
    int ans = 0;
    REP(i, 10){
        REP(j, 10) ans += c[i][j]*c[j][i];
    }
    cout << ans << endl;

    return 0;
}