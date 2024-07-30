#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int X, N;
    cin >> X >> N;
    vector<int> p(N);
    REP(i, N) cin >> p[i];

    auto isInP = [&](int i){
        REP(j, N){
            if(p[j] == i) return true;
        }
        return false;
    };

    int ans, diff = 1000;
    REP(i, 102){
        if(diff > abs(X-i) and !isInP(i)){
            diff = abs(X-i);
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}