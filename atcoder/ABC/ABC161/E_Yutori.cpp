#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vector<int> L(N, 0);  // 左から貪欲に働いたときの仕事日
    vector<int> R(N, 0);  // 右から貪欲に働いた仕事日

    int cnt = 1;
    REP(i, N){
        if(S[i] == 'o'){
            L[i] = cnt;
            i += C;
            ++cnt;
        }
    }

    cnt = K;
    for(int i = N-1; i >= 0; --i){
        if(S[i] == 'o'){
            R[i] = cnt;
            i -= C;
            --cnt;
        }
    }

    REP(i, N){
        if(L[i] != 0 and L[i] == R[i]) cout << i+1 << endl;
    }

    return 0;
}