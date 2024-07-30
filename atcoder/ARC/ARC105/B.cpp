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
    int minimum = 1e+9;
    priority_queue<int> q;
    REP(i, N){
        int a;
        cin >> a;
        minimum = min(minimum, a);
        q.push(a);
    }

    while(q.top() != minimum){
        int large = q.top(); q.pop();
        large -= (large-1)/minimum * minimum;
        q.push(large);
        minimum = min(minimum, large);
    }
    cout << q.top() << endl;

    return 0;
}