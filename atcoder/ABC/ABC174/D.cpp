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
    string c;
    cin >> c;

    int ans = min(count(c.begin(), c.end(), 'R'), count(c.begin(), c.end(), 'W'));

    // 赤白
    int cnt = 0, count_R = count(c.begin(), c.end(), 'R');
    REP(i, count_R){
        if(c[i] == 'W') ++cnt;
    }

    cout << min(ans, cnt) << endl;

    return 0;
}