#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long A;
    cin >> A;
    string b;
    cin >> b;

    long long B = 100*(b[0] -'0') + 10*(b[2]-'0') + (b[3]-'0');
    cout << (A*B) / 100 << endl;

    return 0;
}