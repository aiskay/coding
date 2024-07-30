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


    // N-C を全探索
    long long ans = 0;
    FOR(i, 1, N){
        long long num = 0;
        bool flag = false;
        for(int j = 1; j*j <= i; ++j){
            if(i%j == 0) ++num;
            if(j*j == i) flag = true;
        }
        ans += 2*num;
        if(flag) --ans;
    }
    cout << ans << endl;

    return 0;
}