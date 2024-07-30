#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

struct roulette
{
    int i, num;
    roulette(int i, int num): i(i), num(num) {}

    bool operator < (const roulette& rhs) const { return num > rhs.num; }
};

int main()
{
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    // dp[i] := 後ろから i 番目にn到達するのに必要な最小の手数
    vector<int> dp(N+1, 0);
    priority_queue<roulette> q;
    q.emplace(roulette(N, 0));
    for(int i = N-1; i >= 0; --i){
        if(S[i] == '1') continue;
        auto top = q.top();
        while(!q.empty() and top.i-i > M){
            q.pop();
            top = q.top();
        }
        dp[i] = top.num+1;
        q.push(roulette(i, top.num+1));
    }

    vector<int> ans;
    int curr = 0;
    bool ok = true;
    REP(i, N+1){
        if(S[i] != '1' and dp[curr] != dp[i]){
            if(i - curr > M){
                ok = false;
                break;
            }
            ans.push_back(i-curr);
            curr = i;
        }
    }
    if(ok) for(auto n: ans) cout << n << " ";
    else cout << -1;
    cout << endl;

    return 0;
}