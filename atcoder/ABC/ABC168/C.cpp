#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double theta = 2. * M_PI * (H*60 + M)/(12*60);
    double phi = 2. * M_PI * M/60;
    cout << fixed << setprecision(11) << sqrt(A*A + B*B - 2*A*B*cos(theta-phi)) << endl;

    return 0;
}