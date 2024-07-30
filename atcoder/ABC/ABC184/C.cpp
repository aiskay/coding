#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long r1, c1, r2, c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    // (a, b) -> (c, d) に一回で行けるかどうか
    auto check1 = [&](long long a, long long b, long long c, long long d){
        if(a+b == c+d or a-b == c-d or abs(a-c)+abs(b-d) <= 3) return true;
        else return false;
    };
    auto check2 = [&](int a, int b, int c, int d){
        for(int i = c-3; i <= c+3; ++i){
            for(int j = d-3; j <=d+3; ++j){
                if(abs(i-c)+abs(j-d) <= 3 and check1(a, b, i, j)) return true;
            } 
        }
        return false;
    };

    if(r1 == r2 and c1 == c2) cout << 0 << endl;
    else if(check1(r1, c1, r2, c2)) cout << 1 << endl;
    else if(check2(r1, c1, r2, c2) or (r1+r2+c2-c1)%2 == 0 or (r1+r2+c1-c2)%2 == 0) cout << 2 << endl;
    else cout << 3 << endl;

    return 0;
}