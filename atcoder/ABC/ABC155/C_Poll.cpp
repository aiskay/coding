#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) cin >> S[i];

    int max_appeared = 0;
    map<string, int> num_appeared;
    REP(i, N){
        ++num_appeared[S[i]];
        max_appeared = max(max_appeared, num_appeared[S[i]]);
    }
    
    for(auto p: num_appeared){
        if(p.second == max_appeared) cout << p.first << endl;
    }

    return 0;
}