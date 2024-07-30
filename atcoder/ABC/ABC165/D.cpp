#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long A, B, N;
    cin >> A >> B >> N;

    cout << A*min(N, B-1)/B << endl;

    return 0;
}