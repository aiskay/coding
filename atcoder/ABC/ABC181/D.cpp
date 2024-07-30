#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    string S;
    cin >> S;

    int N = S.size();
    vector<int> num(10, 0);
    REP(i, N) ++num[S[i]-'0'];
    if(N == 1) num[0] += 2; 
    if(N == 2) ++num[0]; 

    for(int prod = 8; prod < 10000; prod += 8){
        if(N == 1 and prod >= 10) break;
        if(N == 2 and prod >= 100) break;
        int hundred = prod/100;
        int ten = (prod/10)%10;
        int one = prod%10;
        if(hundred == ten and ten == one){
            if(num[one] >= 3){
                cout << "Yes" << endl;
                return 0;
            }
        }else if(hundred == ten){
            if(num[ten] >= 2 and num[one] > 0){
                cout << "Yes" << endl;
                return 0;
            }
        }else if(hundred == one){
            if(num[one] >= 2 and num[ten] > 0){
                cout << "Yes" << endl;
                return 0;
            }
        }else if(ten == one){
            if(num[one] >= 2 and num[hundred] > 0){
                cout << "Yes" << endl;
                return 0;
            }
        }else{
            if(num[hundred] > 0 and num[ten] > 0 and num[one] > 0){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}