#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long H;
    cin >> H;

    long long ans = 0, n = 1;
    while(H > 0){
        H /= 2;
        ans += n;
        n *= 2;
    }
    cout << ans << endl;

    return 0;
}