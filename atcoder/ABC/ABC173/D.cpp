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

    sort(A.begin(), A.end(), greater<long long>());

    int i = 1;
    long long ans = 0;
    REP(j, N-1){
        ans += A[i/2];
        ++i;
    }
    cout << ans << endl;

    return 0;
}