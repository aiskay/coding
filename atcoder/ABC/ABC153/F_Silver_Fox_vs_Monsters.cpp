#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


long long solution(vector<pair<long long, long long>>& M, long long D, long long A){
    int N = M.size();
    // 左から見ていくために、座標の昇順でソート
    sort(M.begin(), M.end());

    long long ans = 0, carry = 0;
    queue<pair<long long, long long>> q;
    REP(i, N){
        long long X = M[i].first;
        long long H = M[i].second;
        // これまでの操作の範囲に含まれないものの効果を取り除く
        while(!q.empty() and q.front().first < X){
            carry -= A*q.front().second;
            q.pop();
        }
        H -= carry;
        if(H > 0){
            long long num = (H+A-1)/A;
            ans += num;
            carry += A*num;
            q.emplace(X+2*D, num);
        }
    }
    return ans;
}


/* Binary Indexed Tree (Fenwick Tree)
 * 数列 {v_n} に対して、
 * ・ v[i] += w
 * ・ sum(l,r) = v[l+1]+...+v[r]
 * の操作を O(logN) でしたいって時に使える
 * cf. http://hos.ac/slides/20140319_bit.pdf
 * 1-index と 0-index を使い分けること！ (0-index のsimpleじゃない方の実装怪しい)
 */
template <typename T=long long>
class BIT  
{
    private:
        int sz;  // 1, 2, ..., sz の index を管理
        vector<T> bit;  // BIT を保存する vector; 区間の右端で番号付け

    public:
        BIT(int N): sz(N), bit(N+1, 0) {};

        // v[idx] に w を足す
        void add(int idx, T w){
            // x&(-x) で x の最も下の立っているbit (=各BITが管理する長さ) が取り出せる
            // 自分の番号に自分の長さを足していくと自分が含まれている領域を全て尽くせる
            // for(int x = idx; x <= sz; x += x&(-x)) bit[x] += w;  // 1-index
            for(int x = idx+1; x <= sz; x += x&(-x)) bit[x] += w;  // 0-index simple
            // for(int x = idx; x < sz; x |= x+1) bit[x] += w;  // 0-index 
        }

        // v[1]+...+v[idx] を返す
        T sum(int idx){
            T ret = 0;
            // 区間和は、自分の番号から自分の区間の長さを引くと求まる
            // for(int x = idx; x > 0; x -= x&(-x)) ret += bit[x];  // 1-index
            for(int x = idx+1; x > 0; x -= x&(-x)) ret += bit[x];  // 0-index simple
            // for(int x = idx-1; x >= 0; x = (x&(x+1))-1) ret += bit[x];  // 0-index
            return ret;
        }
        
        // v[left+1]+...+v[right] を返す
        T sum(T left, T right){ return sum(right)-sum(left); }
};

long long solutionWithBIT(vector<pair<long long, long long>>& M, long long D, long long A){
    int N = M.size();
    sort(M.begin(), M.end());
    long long ans = 0;
    BIT<long long> bit(N+1);
    REP(i, N){
        long long X = M[i].first;
        long long H = M[i].second;

        H -= A*bit.sum(i);
        if(H <= 0) continue;
        long long num = (H+A-1)/A;
        ans += num;
        bit.add(i, num);
        int j = distance(M.begin(), lower_bound(M.begin(), M.end(), make_pair(X+2*D+1, (long long) -1)));
        bit.add(j, -num);
    }
    return ans;
}

int main()
{
    int N, D, A;
    cin >> N >> D >> A;
    vector<pair<long long, long long>> M(N);
    REP(i, N) cin >> M[i].first >> M[i].second;

    cout << solutionWithBIT(M, D, A) << endl;

    return 0;
}