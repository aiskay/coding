#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int X;
    cin >> X;

    for(long long a = 0; a <= 3e+3; ++a){
        for(long long b = 0; b <= 3e+3; ++b){
            if(a*a*a*a*a - b*b*b*b*b == X){
                cout << a << " " << b << endl;
                return 0;
            }else if(a*a*a*a*a + b*b*b*b*b == X){
                cout << a << " " << -b << endl;
                return 0;
            }
        }
    }

    return 0;
}