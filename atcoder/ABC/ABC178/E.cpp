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
    vector<pair<int,int>> p(N);
    REP(i, N) cin >> p[i].first >> p[i].second;

    vector<int> s(N), m(N);
    REP(i, N){
        s[i] = p[i].first+p[i].second;
        m[i] = p[i].first-p[i].second;
    }
    sort(s.begin(), s.end());
    sort(m.begin(), m.end());

    cout << max(s.back()-s[0], m.back()-m[0]) << endl;

    return 0;
}