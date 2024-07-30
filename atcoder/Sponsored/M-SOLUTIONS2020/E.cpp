#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

struct city{
    int x, y, P;
    // P が大きい順に sort
    bool operator<(const city& C) const {
        return P > C.P;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<city> C(N);
    REP(i, N){
        int X, Y, P;
        cin >> X >> Y >> P;
    }

    sort(C.begin(), C.end());

    return 0;
}