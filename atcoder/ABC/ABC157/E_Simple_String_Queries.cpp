#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, Q;
    cin >> N;
    string S;
    cin >> S;
    cin >> Q;

    // pos[i] = alphabet i の存在する位置の set
    vector<set<int>> pos('z'-'a'+1);
    REP(i, N) pos[S[i]-'a'].insert(i);

    REP(n, Q){
        int q;
        cin >> q;

        if(q == 1){
            int i;
            char c;
            cin >> i >> c; --i;
            pos[S[i]-'a'].erase(i);
            pos[c-'a'].insert(i);
            S[i] = c;
        }else{
            int l, r;
            cin >> l >> r; --l, --r;
            int ans = 0;
            REP(i, 'z'-'a'+1){
                if(distance(pos[i].lower_bound(l), pos[i].upper_bound(r)) > 0) ++ans;
            }
            cout << ans << endl;
        }
    }


    return 0;
}