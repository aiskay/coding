#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    REP(i, N) cin >> x[i] >> y[i];

    REP(i, N){
        FOR(j, i+1, N){
            FOR(k, j+1, N){
                if((x[j]-x[i])*(y[k]-y[i]) == (y[j]-y[i])*(x[k]-x[i])){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}