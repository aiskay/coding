#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    REP(i, N) cin >> A[i];

    FOR(i, K, N){
        if(A[i] > A[i-K]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}