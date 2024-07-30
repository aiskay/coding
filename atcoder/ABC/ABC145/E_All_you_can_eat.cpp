#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

int solution_sort(vector<pair<int,int>>& dish, int T)
{
    int N = dish.size();
    sort(dish.begin(), dish.end());
    
    int ans = 0;
    vector<int> dp(T, 0);
    for(int i = 0; i < N; ++i){
        int A = dish[i].first;
        int B = dish[i].second;
        ans = max(ans, dp[T-1]+B);
        for(int j = T-1; j >= A; --j) dp[j] = max(dp[j], dp[j-A]+B);
    }
    return ans;
}

int solution_dp(vector<pair<int,int>>& dish, int T)
{
    int N = dish.size();
    
    vector<vector<int>> dp(N+1, vector<int>(T, 0)), dpr(N+1, vector<int>(T, 0));
    for(int i = 1; i < N+1; ++i){
        int A = dish[i-1].first;
        int B = dish[i-1].second;
        for(int j = 0; j < T; ++j){
            if(j >= A) dp[i][j] = max(dp[i-1][j], dp[i-1][j-A]+B);
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i = N-1; i >= 1; --i){
        int A = dish[i].first;
        int B = dish[i].second;
        for(int j = 0; j < T; ++j){
            if(j >= A) dpr[i-1][j] = max(dpr[i][j], dpr[i][j-A]+B);
            else dpr[i-1][j] = dpr[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N; ++i){
        int B = dish[i].second;
        for(int j = 0; j < T; ++j) ans = max(ans, dp[i][j]+dpr[i][T-j-1]+B);
    }
    
    return ans;
}

int main()
{
    int N, T;
    cin >> N >> T;
    vector<pair<int,int>> dish(N);
    REP(i, N) cin >> dish[i].first >> dish[i].second;

    cout << solution_dp(dish, T) << endl;

    return 0;
}