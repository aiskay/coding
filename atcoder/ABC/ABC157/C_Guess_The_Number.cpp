#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


bool check(vector<int>& s, vector<int>& c, vector<int>& ans)
{
    int N = ans.size();
    int M = s.size();
    REP(i, M){
        if(ans[s[i]] == -1 or ans[s[i]] == c[i]) ans[s[i]] = c[i];
        else return false;
    }
    if(N > 1 and ans[0] == 0) return false;
    if(N == 1 and ans[0] == -1) ans[0] = 0;
    REP(i, N) if(ans[i] == -1) ans[i] = (i==0)? 1: 0;

    return true;
}


int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> s(M), c(M);
    REP(i, M){
        cin >> s[i] >> c[i];
        --s[i];
    }

    vector<int> ans(N, -1);
    if(check(s, c, ans)){
        REP(i, N) cout << ans[i];
        cout << endl;
    }else cout << -1 << endl;

    return 0;
}