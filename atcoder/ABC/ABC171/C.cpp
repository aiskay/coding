#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long N;
    cin >> N;

    string ans;
    while(N > 0){
        --N;
        ans += 'a' + N%26;
        N /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}