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

    long long ans = 0;
    int max_height = 0;
    REP(i, N){
        ans += max(0, max_height-A[i]);
        max_height = max(max_height, A[i]);
    }
    cout << ans << endl;

    return 0;
}