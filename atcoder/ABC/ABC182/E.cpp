#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    vector<int> A(N), B(N);
    vector<vector<int>> matrix(H, vector<int>(W, 0));
    REP(i, N){
        cin >> A[i] >> B[i];
        --A[i], --B[i];
    }
    REP(i, M){
        int C, D;
        cin >> C >> D;
        --C, --D;
        matrix[C][D] = -1;
    }

    // 行方向
    REP(k, N){
        int j = B[k];
        FOR(i, A[k], H){
            if(matrix[i][j] == 1 or matrix[i][j] == -1) break;
            matrix[i][j] = 1;
        }
        for(int i = A[k]-1; i >= 0; --i){
            if(matrix[i][j] == 1 or matrix[i][j] == -1) break;
            matrix[i][j] = 1;
        }
    }
    // 列方向
    REP(k, N){
        int i = A[k];
        FOR(j, B[k], W){
            if(matrix[i][j] == 2 or matrix[i][j] == -1) break;
            matrix[i][j] = 2;
        }
        for(int j = B[k]-1; j >= 0; --j){
            if(matrix[i][j] == 2 or matrix[i][j] == -1) break;
            matrix[i][j] = 2;
        }
    }

    int ans = 0;
    REP(i, H){
        REP(j, W){
            if(matrix[i][j] == 1 or matrix[i][j] == 2) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}