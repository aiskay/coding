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
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    vector<int> num_balls(N+1);
    REP(i, N) ++num_balls[A[i]];

    long long ans = 0;
    REP(i, N+1) ans += (long long) num_balls[i]*(num_balls[i]-1)/2;
    REP(k, N) cout << ans - (num_balls[A[k]]-1) << endl; 

    return 0;
}