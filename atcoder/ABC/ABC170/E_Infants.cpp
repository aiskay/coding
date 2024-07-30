#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int num_kindergarden = 2e+5;

struct infant
{
    int kindergarden;
    int rating;
    infant(int k, int r): kindergarden(k), rating(r) {}
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<infant> child;
    vector<multiset<int>> kindergarden(num_kindergarden);
    REP(i, N){  // i-th infant
        int A, B;  // A: rating, B: number of Kindergarder
        cin >> A >> B;
        --B;
        kindergarden[B].insert(A);
        child.emplace_back(infant(B, A));
    } 

    multiset<int> max_rating;
    for(auto s: kindergarden){
        if(!s.empty()) max_rating.insert(*s.rbegin());
    }

    REP(i, Q){
        int C, D;
        cin >> C >> D;  // C infants -> D kindergarden
        --C, --D;

        // とりあえず毎回その幼稚園の最大値を削除して、幼児を取り除い(挿入し)た後に最大値を再び挿入すればよい
        // remove
        max_rating.erase(max_rating.find(*kindergarden[child[C].kindergarden].rbegin()));
        kindergarden[child[C].kindergarden].erase(child[C].rating);
        if(!kindergarden[child[C].kindergarden].empty()) max_rating.insert(*kindergarden[child[C].kindergarden].rbegin());

        child[C].kindergarden = D;

        // add
        if(!kindergarden[child[C].kindergarden].empty()) max_rating.erase(max_rating.find(*kindergarden[child[C].kindergarden].rbegin()));
        kindergarden[child[C].kindergarden].insert(child[C].rating);
        max_rating.insert(*kindergarden[child[C].kindergarden].rbegin());

        cout << *max_rating.begin() << endl;
    }

    return 0;
}