#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int H, W, M;
    cin >> H >> W >> M;
    set<pair<int, int>> p;
    vector<pair<int, int>> num_h(H), num_w(W);
    REP(i, M){
        int h, w;
        cin >> h >> w;
        --h, --w;
        p.insert(make_pair(h, w));
        num_h[h].second = h;
        num_w[w].second = w;
        ++num_h[h].first;
        ++num_w[w].first;
    }

    sort(num_h.begin(), num_h.end(), greater<pair<int, int>>());
    sort(num_w.begin(), num_w.end(), greater<pair<int, int>>());
    
    cout << num_h[0].second << " " << num_w[0].second << endl;
    if(p.find(make_pair(num_h[0].second, num_w[0].second)) != p.end()) cout << num_h[0].first+num_w[0].first-1 << endl;
    else cout << num_h[0].first+num_w[0].first << endl;

    return 0;
}