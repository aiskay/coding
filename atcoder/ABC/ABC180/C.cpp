#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long N;
    cin >> N;

    vector<long long> ans;
    for(long long i = 1; i*i <= N; ++i){
        if(i*i == N) cout << i << endl;
        else if(N%i == 0){
            cout << i << endl;
            ans.push_back(N/i);
        }
    }
    sort(ans.begin(), ans.end());

    for(auto v: ans) cout << v << endl; 

    return 0;
}