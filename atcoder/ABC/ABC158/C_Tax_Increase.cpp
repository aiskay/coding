#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int A, B;
    cin >> A >> B;

    int ans = -1;
    FOR(i, 1, 100000){
        if(2*i/25 == A and i/10 == B){
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}