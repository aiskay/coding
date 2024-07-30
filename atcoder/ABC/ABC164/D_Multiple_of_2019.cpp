#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int solution(string& S)
{
    int N = S.size();
    vector<int> num_appeared(2019, 0);  // 余り i の現れた回数
    num_appeared[0] = 1;
    int ans = 0, res = 0, digit = 1;
    for(int i = N-1; i >=0; --i){
        res = (digit*(S[i]-'0')+res) % 2019;
        digit = (10*digit) % 2019;
        ans += num_appeared[res];
        ++num_appeared[res];
    }
    return ans;
}

int main()
{
    string S;
    cin >> S;

    cout << solution(S) << endl;

    return 0;
}