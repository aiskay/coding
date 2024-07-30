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
    FOR(i, 1, N){
        cin >> A[i];
        --A[i];
    }

    vector<int> num_sub(N, 0);
    FOR(i, 1, N) ++num_sub[A[i]];
    REP(i, N) cout << num_sub[i] << endl;

    return 0;
}