#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
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
    map<int, int> num_appear;
    REP(i, N){
        ans += num_appear[i-A[i]];
        ++num_appear[i+A[i]];
    }
    cout << ans << endl;

    return 0;
}