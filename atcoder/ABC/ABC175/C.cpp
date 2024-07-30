#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long X, K, D;
    cin >> X >> K >> D;

    long long n = llabs(X)/D;
    if(n < K){
        X = abs(X);
        if(n%2 == K%2) cout << X%D << endl;
        else cout << llabs(X%D-D) << endl;
    }else{
        if(X <= 0) cout << llabs(X+K*D) << endl;
        if(X >  0) cout << X-K*D << endl;
    }

    return 0;
}