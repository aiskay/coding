#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

int main()
{
    long long N;
    cin >> N;

    long long tmp = N;
    // M の約数でかつ M 以下の素数を列挙
    vector<long long> prime;
    for(long long p = 2; p*p <= N; ++p){
        if(tmp%p == 0){
            while(tmp%p == 0) tmp /= p;
            prime.push_back(p);
        }
    }
    if(tmp > 1) prime.push_back(tmp);

    int ans = 0;
    for(auto p: prime){
        long long div = p;
        while(N%div == 0){
            N /= div;
            div *= p;
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}