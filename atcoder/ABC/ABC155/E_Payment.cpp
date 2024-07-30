#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    string S;
    cin >> S;

    S = '0'+S;
    int ans = 0, carry = 0;
    for(int i = S.size()-1; i > 0; --i){
        int now = (S[i]-'0') + carry;
        ans += min(now, 10-now);
        if(now > 5 or (now == 5 and S[i-1] >= '5')) carry = 1;
        else carry = 0;
    }
    cout << ans+carry << endl;

    return 0;
}