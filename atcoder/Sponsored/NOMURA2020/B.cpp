#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    string T;
    cin >> T;

    int N = T.size();
    REP(i, N){
        if(T[i] == '?') cout << 'D';
        else cout << T[i];
    }
    cout << endl;

    return 0;
}