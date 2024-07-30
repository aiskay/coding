#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int K;
    cin >> K;

    queue<long long> q;
    FOR(i, 1, 10) q.push(i);

    REP(i, K-1){
        long long x = q.front();
        q.pop();
        if(x%10 != 0) q.push(10*x + x%10 - 1);
        q.push(10*x + x%10);
        if(x%10 != 9) q.push(10*x + x%10 + 1);
    }
    cout << q.front() << endl;

    return 0;
}