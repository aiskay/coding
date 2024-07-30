#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

/* データを互いに重複しない集合に分割して保持するデータ構造を
 * 素集合データ構造 (Disjoint-set Data Structure) という。
 * このデータ構造に対して
 *  ・Find:  特定の要素がどの集合に属しているかを求める
 *  ・Union: 2つの集合を統合する
 * のアルゴリズムを兼ね備えたデータ構造を Union Find データ構造と呼ぶ。
 */

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


int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    REP(i, M) cin >> A[i] >> B[i];

    UnionFind uni(N);
    REP(i, M) uni.unite(A[i]-1, B[i]-1);

    int ans = 0;
    REP(i, N){
        if(uni.find(i) == i) ans = max(ans, int(uni.size(i)));
    }
    cout << ans << endl;

    return 0;
}