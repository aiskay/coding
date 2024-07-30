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
    vector<long long> A(N);
    REP(i, N) cin >> A[i];

    vector<long long> B(A);
    REP(i, N-1) B[i+1] += B[i];
    REP(i, N-1) B[i+1] = max(B[i], B[i+1]);

    REP(i, N-1) A[i+1] += A[i];
    REP(i, N-1) A[i+1] += A[i];

    long long ans = max((long long) 0, A[0]);
    FOR(i, 1, N) ans = max(ans, A[i-1]+B[i]);
    cout << ans << endl;

    return 0;
}