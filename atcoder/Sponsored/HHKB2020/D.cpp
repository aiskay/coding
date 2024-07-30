#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

int main()
{
    int T;
    cin >> T;

    REP(_, T){
        long long N, A, B;
        cin >> N >> A >> B;

        long long ans = 0;
        // long long num_A = (N-A+1)*(N-A+1) % MOD;  // A の正方形の全置き方
        // A のそれぞれの置き方に対する B の正方形の置き方
        long long num_B = 0;
        if(N+1 > A+B){
            num_B += (N+1-(A+B))*(N+1-(A+B)) % MOD;  // 端っこを除いた場合
            num_B += B/2*(B+1)*(2*A+B);  // 端っこの全通り
        }else{

        }
        cout << num_B%MOD << endl;
    }

    

    return 0;
}