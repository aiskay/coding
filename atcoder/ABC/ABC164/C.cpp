#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) cin >> S[i];

    set<string> kind;
    REP(i, N) kind.insert(S[i]);
    cout << kind.size() << endl;

    return 0;
}