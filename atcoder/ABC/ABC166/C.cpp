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
    vector<int> H(N);
    REP(i, N) cin >> H[i];
    vector<vector<int>> G(N);
    REP(i, M){
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    int ans = 0;
    REP(i, N){
        bool is_good = true;
        for(auto e: G[i]){
            if(H[i] <= H[e]){
                is_good = false; 
                break;
            } 
        }
        if(is_good) ++ans;
    } 
    cout << ans << endl;

    return 0;
}