#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, M;
    cin >> N >> M;

    if(N == 1 and M == 0) cout << 1 << " " << 2 << endl;
    else if(M < 0 or M >= N-1) cout << -1 << endl;
    else{
        cout << 1 << " " << int(1e+9) << endl;
        REP(i, M){
            cout << 2*(i+1) << " " << 2*(i+1)+1 << endl;
        }
        REP(i, N-(M+1)){
            cout << 2*M+(i+2) << " " << int(1e+9)-(i+1) << endl;
        }
    }

    return 0;
}