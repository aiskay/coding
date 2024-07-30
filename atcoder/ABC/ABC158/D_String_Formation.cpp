#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    int num_reverse = 0;
    REP(i, Q){
        int T;
        cin >> T;

        if(T == 1) ++num_reverse;
        if(T == 2){
            int F;
            char C;
            cin >> F >> C;

            if((F == 1 and num_reverse%2 == 0) or (F == 2 and num_reverse%2 == 1)) S.insert(S.begin(), C);
            if((F == 2 and num_reverse%2 == 0) or (F == 1 and num_reverse%2 == 1)) S += C;
        }
    }
    if(num_reverse%2 == 1) reverse(S.begin(), S.end());
    cout << S << endl;

    return 0;
}