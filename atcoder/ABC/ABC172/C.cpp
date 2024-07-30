#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long M, N, K;
    cin >> N >> M >> K;
    vector<long long> A(N+1, 0), B(M+1, 0);
    FOR(i, 1, N+1) cin >> A[i];
    FOR(i, 1, M+1) cin >> B[i];

    REP(i, N) A[i+1] += A[i];
    REP(i, M) B[i+1] += B[i];
    
    int ans = 0;
    REP(i, N+1){
        if(A[i] > K) break;
        int j = lower_bound(B.begin(), B.end(), K-A[i]) - B.begin();
        if(B[j] == K-A[i]) ans = max(ans, i+j);
        else ans = max(ans, i+j-1);
    }
    cout << ans << endl;

    return 0;
}