#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    vector<pair<long long, int>> A(N), tmp(N);
    REP(i, N){
        A[i].second = tmp[i].second = i;
        cin >> A[i].first;
        tmp[i].first = A[i].first;
    }

    sort(tmp.begin(), tmp.end(), greater<pair<long long, int>>());

    // 大きい順に位置を決めていく
    vector<pair<long long, int>> ans(N);
    REP(i, N){
        int pos = i;
        long long happiness = 0;
        REP(j, N){
            if(ans[j].first != 0) continue;
            long long tmp_happiness = tmp[i].first*abs(tmp[i].second-j) + A[j].first*abs(A[j].second-tmp[i].second);
            //cout << tmp[i].first*abs(tmp[i].second-j) << " " << A[j].first*abs(A[j].second-i) << endl;
            if(tmp[i].first*abs(tmp[i].second-) < tmp_happiness and tmp_happiness > happiness){
                pos = j;
                happiness = tmp_happiness;
            }
        }
        ans[pos] = tmp[i];
        swap(A[i], A[pos]);
    }

    long long s = 0;
    REP(i, N) s += ans[i].first*abs(ans[i].second-i);
    cout << s << endl;

    return 0;
}