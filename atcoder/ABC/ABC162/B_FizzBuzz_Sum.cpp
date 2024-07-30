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

    long long ans = 0;
    FOR(i, 1, N+1){
        if(i%3 == 0 and i%5 == 0) continue;
        else if(i%3 == 0) continue;
        else if(i%5 == 0) continue;
        else ans += i;
    }
    cout << ans << endl;

    return 0;
}