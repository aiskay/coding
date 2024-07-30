#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long X, Y, A, B;
    cin >> X >> Y >> A >> B;

    long long ans = 0;
    while(A < 1+B/X and A < Y/X){
        X *= A;
        ++ans;
    }
    cout << ans + (Y-X-1)/B << endl;
    
    return 0;
}