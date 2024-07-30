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
    string S;
    cin >> S;


    // 累積和
    vector<vector<int>> num(N+1, vector<int>(4, 0));
    FOR(i, 1, N+1){
        REP(j, 4) num[i][j] += num[i-1][j];
        if(S[i-1] == 'A') ++num[i][0];
        if(S[i-1] == 'T') ++num[i][1];
        if(S[i-1] == 'C') ++num[i][2];
        if(S[i-1] == 'G') ++num[i][3];
    }

    long long ans = 0;
    // [i, j] が相補的かどうか
    FOR(i, 1, N+1){
        FOR(j, i, N+1){
            if(num[j][0]-num[i-1][0] == num[j][1]-num[i-1][1] and num[j][2]-num[i-1][2] == num[j][3]-num[i-1][3]) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}