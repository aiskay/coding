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

    vector<long long> s(A);
    for(int i = N-2; i >= 0; --i){
        s[i] += s[i+1];
        s[i] %= MOD;
    }

    long long ans = 0;
    REP(i, N-1){
        ans += s[i+1]*A[i] % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}