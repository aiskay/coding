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
    vector<long long> a(N);
    REP(i, N) cin >> a[i];

    long long all = 0;
    REP(i, N) all ^= a[i];
    REP(i, N) cout << (all^a[i]) << endl;

    return 0;
}