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
    vector<int> X(N);
    REP(i, N) cin >> X[i];

    int ans = 1e+7;
    FOR(P, 1, 101){
        int tot_stamina = 0;
        REP(i, N) tot_stamina += (X[i]-P)*(X[i]-P);
        ans = min(ans, tot_stamina);
    }
    cout << ans << endl;

    return 0;
}