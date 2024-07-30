#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


bool solution(vector<int>& num, vector<string>& s, vector<char>& ans){
    int N = s.size();
    REP(i, N){
        // 選ばれているものを数字に変換
        int i1 = s[i][0] - 'A';
        int i2 = s[i][1] - 'A';
        int large = i1, small = i2;

        if(num[i1]+num[i2] == 0) return false;
        else if(num[i1] == 1 and num[i2] == 1){  // s
            if(i+1 < N and (s[i+1][0] == s[i][0] or s[i+1][1] == s[i][0])){
                small = i1;
                large = i2;
            }
        }else if(num[i1] < num[i2]){  // 基本的には大きい方から小さい方に持っていく
            small = i1;
            large = i2;
        }
        ans.push_back(small+'A');
        ++num[small];
        --num[large];
    }
    return true;
}


int main()
{
    int N;
    vector<int> num(3);
    cin >> N >> num[0] >> num[1] >> num[2];
    vector<string> s(N);
    REP(i, N) cin >> s[i];

    vector<char> ans;
    if(solution(num, s, ans)){
        cout << "Yes" << endl;
        for(auto c: ans) cout << c << endl;
    }else cout << "No" << endl;

    return 0;
}