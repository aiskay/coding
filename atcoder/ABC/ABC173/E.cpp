#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9+7;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> p, n;
    REP(i, N){
        long long A;
        cin >> A;
        if(A >= 0) p.push_back(A);
        else n.push_back(A);
    }

    sort(p.begin(), p.end());
    sort(n.begin(), n.end());

    int ps = p.size();
    int ns = n.size();
    long long ans = 1;
    if(N == K){
        REP(i, ps) ans = (ans*p[i])%MOD;
        REP(i, ns) ans = (ans*n[i])%MOD;
    }else if(ns == N){
        if(K%2 == 0) REP(i, K) ans = (ans*n[i])%MOD;
        if(K%2 == 1) REP(i, K) ans = (ans*n[N-1-i])%MOD;
    }else{
        int i = ps-1, j = 0;
        if(K%2 == 1){
            ans *= p[i];
            ans %= MOD;
            --i, --K;
        }
        while(K){
            if((0 <= i-1 and j+1 < ns and p[i-1]*p[i] >= n[j]*n[j+1]) or j >= ns-1){
                ans *= p[i-1]*p[i] % MOD; 
                ans %= MOD;
                i -= 2;
            }else{
                ans *= n[j]*n[j+1] % MOD; 
                ans %= MOD;
                j += 2;
            }
            K -= 2;
        }
    }
    cout << (ans+MOD)%MOD << endl;

    return 0;
}