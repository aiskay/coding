#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

long long calc(long long N, long long A, long long B, long long C, long long D, map<long long, long long>& mp)
{
    if(N == 1) return D;
    if(mp.count(N)) return mp[N];

    long long y, t;
    mp[N] = 1e+18;
    if(1e+18/D > N) mp[N] = N*D;

    for(t = 0, y = N; y%2 != 0; ++y, ++t);
    mp[N] = min(mp[N], (y/2? calc(y/2, A, B, C, D, mp)+A: 0) + t*D);
    for(t = 0, y = N; y%2 != 0; --y, ++t);
    mp[N] = min(mp[N], (y/2? calc(y/2, A, B, C, D, mp)+A: 0) + t*D);

    for(t = 0, y = N; y%3 != 0; ++y, ++t);
    mp[N] = min(mp[N], (y/3? calc(y/3, A, B, C, D, mp)+B: 0) + t*D);
    for(t = 0, y = N; y%3 != 0; --y, ++t);
    mp[N] = min(mp[N], (y/3? calc(y/3, A, B, C, D, mp)+B: 0) + t*D);

    for(t = 0, y = N; y%5 != 0; ++y, ++t);
    mp[N] = min(mp[N], (y/5? calc(y/5, A, B, C, D, mp)+C: 0) + t*D);
    for(t = 0, y = N; y%5 != 0; --y, ++t);
    mp[N] = min(mp[N], (y/5? calc(y/5, A, B, C, D, mp)+C: 0) + t*D);

    return mp[N];
}

int main()
{
    int T;
    cin >> T;

    while(T--){
        long long N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;

        map<long long, long long> mp;
        cout << calc(N, A, B, C, D, mp) << endl;
    }

    return 0;
}