#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = -1; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long N, X, M;
    cin >> N >> X >> M;

    vector<long long> b, l;
    vector<bool> is_appeared(M, false);
    REP(i, M){
        if(is_appeared[X]) break;
        is_appeared[X] = true;
        b.push_back(X);
        X *= X;
        X %= M;
    }
    while(!b.empty()){
        long long tmp = b.back();
        b.pop_back();
        l.push_back(tmp);
        if(tmp == X) break;
    }
    reverse(l.begin(), l.end());

    long long ans = accumulate(b.begin(), b.end(), (long long) 0);
    if((long long) b.size() < N){
        N -= (long long) b.size();
        long long s = accumulate(l.begin(), l.end(), (long long) 0);
        long long len = l.size();
        ans += s * (N/len);
        for(int i = 0; i < N%len; ++i) ans += l[i];
    }
    cout << ans << endl;

    return 0;
}