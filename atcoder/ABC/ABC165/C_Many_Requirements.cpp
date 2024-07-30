#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

vector<int> a, b, c, d;


int dfs(vector<int> A, int ret, int N, int M, int Q){
    if(A.size() == N){
        int s = 0;
        REP(i, Q){
            if(A[b[i]] - A[a[i]] == c[i]) s += d[i];
        }
        return max(s, ret);
    }

    if(A.size() == 0) A.push_back(1);
    FOR(i, A.back(), M+1){
        A.push_back(i);
        ret = max(ret, dfs(A, ret, N, M, Q));
        A.pop_back();
    }

    return ret;
}

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    a = b = c= d= vector<int>(Q);
    REP(i, Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i], --b[i];
    }

    // あり得る数列を全探索
    cout << dfs(vector<int>(0), 0, N, M, Q) << endl;

    return 0;
}