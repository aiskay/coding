#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int K;
    cin >> K;

    long long m = 0;
    for(int i = 1; i < 1e+7; ++i){
        m = (10*m+7)%K;
        if(m == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}