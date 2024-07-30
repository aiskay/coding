#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    long long N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N){
        cin >> A[i];
        --A[i];
    }

    vector<int> num_visit(N, -1);
    num_visit[0] = 0;
    int i = 1, next = A[0];
    while(num_visit[next] == -1){
        // cout << next << " " << A[next] << " " << i << endl;
        num_visit[next] = i;
        next = A[next];
        ++i;
    }

    int loop = i-num_visit[next];
    REP(i, N){
        if(K <= num_visit[next]){
            if(num_visit[i] == K){
                cout << i+1 << endl;
                break;
            }
        }else if(num_visit[i]-num_visit[next] == (K-num_visit[next])%loop){
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}