#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

class UnionFind
{
    private:
        std::vector<int> parent;  // parent[x]: x の根の番号
                                  //            x が根の場合はその連結成分の大きさ
        std::vector<int> rank;    // rank[x]  : x が属する木の高さ
        std::size_t sz;           // 連結成分の数

    public:
        // x が親の場合、parent[x] = -(その連結成分の大きさ)
        UnionFind( std::size_t n ): parent(n, -1), rank(n, 0), sz(n) {}

        // x が属する集合の親を返し、x を親に直接繋ぎ直す(経路圧縮)
        int find( int x )
        {
            if( parent[x] < 0 ) return x;
            else return parent[x] = find( parent[x] );
        }

        // x が属する集合と y が属する集合を統合する
        bool unite( int x, int y )
        {
            x = find( x );
            y = find( y );
            if( x == y ) return false;

            // 大きい方(x)に小さい方(y)を繋げる
            if( rank[x] < rank[y] ) std::swap( x, y );

            parent[x] += parent[y];  // x に連結している成分の大きさを更新する
            parent[y] = x;           // y を x に繋ぐ
            if( rank[x] == rank[y] ) rank[x]++;
            sz--;

            return true;
        }

        bool same( int x, int y ) { return find(x) == find(y); }
        std::size_t size()        { return sz; }
        std::size_t size( int x ) { return - parent[find(x)]; }
};

const int MOD = 998244353;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> a(N, vector<int>(N));
    REP(i, N){
        REP(j, N) cin >> a[i][j];
    }

    auto can_swap = [&](int i, int j, bool is_row){
        REP(k, N){
            if(is_row){
                if(i == j or a[i][k] + a[j][k] > K) return false;
            }else{
                if(i == j or a[k][i] + a[k][j] > K) return false;
            }
        }
        return true;
    };

    UnionFind uni_row(N), uni_col(N);
    REP(i, N){
        REP(j, N){
            if(can_swap(i, j, true)) uni_row.unite(i, j);
            if(can_swap(i, j, false)) uni_col.unite(i, j);
        }
    }

    long long row = 1, col = 1;
    REP(i1, N){
        bool flag = true;
        REP(i2, i1){
            if(uni_row.same(i1, i2)){
                flag = false;
                break;
            }
        }
        if(flag){
            long long tmp = 1;
            FOR(k, 1, uni_row.size(i1)+1){
                tmp *= k;
                tmp %= MOD; 
            }
            row *= tmp;
            row %= MOD;
        }
    }
    REP(j1, N){
        bool flag = true;
        REP(j2, j1){
            if(uni_col.same(j1, j2)){
                flag = false;
                break;
            }
        }
        if(flag){
            long long tmp = 1;
            FOR(k, 1, uni_col.size(j1)+1){
                tmp *= k;
                tmp %= MOD; 
            }
            col *= tmp;
            col %= MOD;
        }
    }
    cout << row*col%MOD << endl;

    return 0;
}