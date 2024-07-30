#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<int> p(A), q(B), r(C);
    REP(i, A) cin >> p[i];
    REP(i, B) cin >> q[i];
    REP(i, C) cin >> r[i];

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());

    priority_queue<int> cand;
    REP(i, X) cand.push(p[i]);
    REP(i, Y) cand.push(q[i]);
    REP(i, C) cand.push(r[i]);

    long long ans = 0;
    REP(i, X+Y){
        ans += cand.top();
        cand.pop();
    }
    cout << ans << endl;

    return 0;
}