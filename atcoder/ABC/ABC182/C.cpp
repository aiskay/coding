#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main()
{
    string S;
    cin >> S;

    vector<int> digit;
    for(auto s: S){
        int n = s-'0';
        digit.push_back(n);
    }

    int ans = -1;
    FOR(k, 1, digit.size()+1){
        foreach_comb(digit.size(), k, [&](int *indexes){
            int s = 0;
            REP(i, k) s += digit[indexes[i]];
            if(s%3 == 0) ans = int(S.size())-k;
        });
    }
    cout << ans << endl;

    return 0;
}