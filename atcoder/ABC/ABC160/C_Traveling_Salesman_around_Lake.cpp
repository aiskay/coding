#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int K, N;
    cin >> K >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    int max_diff = K-A[N-1]+A[0];
    REP(i, N-1) max_diff = max(max_diff, A[i+1]-A[i]);
    cout << K-max_diff << endl;

    return 0;
}