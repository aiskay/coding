#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long N, K;
    cin >> N >> K;

    cout << min(N%K, abs(N%K-K)) << endl;

    return 0;
}