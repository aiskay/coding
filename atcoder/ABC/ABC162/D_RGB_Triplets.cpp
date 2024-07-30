#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    // 面倒くさいので R, G, B を 0, 1, 2 に置き換える
    string T;
    REP(i, N){
        if(S[i] == 'R') T += '0';
        if(S[i] == 'G') T += '1';
        if(S[i] == 'B') T += '2';
    }
    // R, G, B の累積個数を後ろから数える
    vector<vector<int>> num(3, vector<int>(N+1));
    for(int i = N-1; i >= 0; --i){
        REP(j, 3) num[j][i] = num[j][i+1];
        ++num[int(T[i]-'0')][i];
    }

    long long ans = 0;
    REP(i, N){
        FOR(j, i+1, N-1){
            if(T[i] == T[j]) continue;
            int tmp = 3-int(T[i]-'0')-int(T[j]-'0');
            ans += num[tmp][j+1];
            if(2*j-i < N and T[2*j-i] == char('0'+tmp)) --ans;
        }
    }
    cout << ans << endl;
    

    return 0;
}