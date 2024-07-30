#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

// 全てを c 以下にするのに必要な回数
bool is_larger(long long c, long long K, vector<long long>& A)
{
    int N = A.size();
    long long cnt = 0;
    REP(i, N){
        cnt += (A[i]-1)/c;
        if(cnt > K) return true;
    }
    return false;
}

int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    REP(i, N) cin >> A[i];

    long long l = 1, r = 1e+9;
    while(l+1 < r){
        long long c = (l+r)/2;
        if(is_larger(c, K, A)) l = c;
        else r = c;
    }
    if(is_larger(l, K, A)) cout << r << endl;
    else cout << l << endl;

    return 0;
}