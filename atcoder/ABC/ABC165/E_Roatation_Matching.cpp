#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, M;
    cin >> N >> M;

    int i = 1, j = (N+1)/2, count = 0;
    // 前半
    while(i < j){
        cout << i << " " << j << endl;
        ++i, --j, ++count;
        if(count == M) return 0;
    }
    // 後半
    i = (N+1)/2+1, j = (N%2 == 0)? N-1: N;
    REP(k, M){
        cout << i << " " << j << endl;
        ++i, --j, ++count;
        if(count == M) return 0;
    }

    return 0;
}