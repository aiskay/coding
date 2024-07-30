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

    FOR(i, 1, 50){
        bool flag = true;
        long long num3 = 1;
        REP(k, i){
            num3 *= 3;
            if(num3 > N){
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        FOR(j, 1, 30){
            long long num5 = 1;
            REP(k, j){
                num5 *= 5;
                if(num3+num5 > N){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            if(num3 + num5 == N){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}