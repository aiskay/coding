#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

bool pairwiseDistinct(vector<long long>& A)
{
    int N = A.size();
    vector<bool> is_appeared(1e+9+1, false);
    REP(i, N){ 
        if(is_appeared[A[i]]) return false;
        else is_appeared[A[i]] = true;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    REP(i, N) cin >> A[i];

    if(pairwiseDistinct(A)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}