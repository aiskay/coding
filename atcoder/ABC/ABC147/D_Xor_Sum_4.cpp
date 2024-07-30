#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    REP(i, N) cin >> A[i];

    long long ans = 0;
    for(int i = 0; i < 60; ++i){
        long long count = 0;
        REP(j, N){
            if(A[j] & ((long long) 1<<i)) ++count;
        }
        ans += (count*(N-count) %MOD) * (((long long) 1<<i) % MOD);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}