#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

int main()
{
    int N;
    cin >> N;
    vector<int> num(1e+5+1, 0);
    REP(i, N){
        int A;
        cin >> A;
        ++num[A];
    }
    int Q;
    cin >> Q;

    long long ans = 0;
    REP(i, 1e+5+1) ans += i*num[i];
    REP(i, Q){
        int B, C;
        cin >> B >> C;
        ans += (C-B)*num[B];
        num[C] += num[B];
        num[B] = 0;
        cout << ans << endl;
    }

    return 0;
}