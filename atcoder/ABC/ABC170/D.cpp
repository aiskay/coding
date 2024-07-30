#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

int main()
{
    int N;
    cin >> N;
    set<int> s;
    vector<int> num(1e+6+1, 0);
    REP(i, N){
        int A;
        cin >> A;
        s.insert(A);
        ++num[A];
    }

    int ans = 0;
    vector<bool> divide(1e+6+1, false);
    for(auto v: s){
        if(!divide[v] and num[v] == 1) ++ans;
        int tmp = v;
        for(int j = 1; tmp <= 1e+6; ++j){
            tmp = v*j;
            divide[tmp] = true;
        }
    }
    cout << ans << endl;

    return 0;
}