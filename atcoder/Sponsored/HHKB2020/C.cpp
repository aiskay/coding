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
    vector<int> p(N);
    REP(i, N) cin >> p[i];

    int ans = 0;
    vector<int> num_appeared(200001, 0);
    REP(i, N){
        ++num_appeared[p[i]];
        while(num_appeared[ans] > 0) ++ans;
        cout << ans << endl;
    }

    return 0;
}