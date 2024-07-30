#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

int solution(vector<int>& A, vector<int>& B)
{
    int N = A.size();
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if(N%2 == 1) return B[N/2]-A[N/2]+1;
    else{
        // /2 ではなく足し上げたものが中央値だと思う
        int l = A[N/2-1]+A[N/2];
        int r = B[N/2-1]+B[N/2];
        return r-l+1;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];

    cout << solution(A, B) << endl;

    return 0;
}