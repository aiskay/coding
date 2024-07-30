#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

bool check(int i, vector<int>& A){
    FOR(j, i+1, A.size()) if(A[i] < A[j]) return true;
    return false;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    long long money = 1000, stock = 0, price = 1e+9;
    REP(i, N){
        if(check(i, A) and price > A[i]){
            while(i+1 < N and A[i] >= A[i+1]) ++i;
            stock = money/A[i];
            money -= stock*A[i];
            price = A[i];
        }else if(A[i] > price){
            while(i+1 < N and A[i] <= A[i+1]) ++i;
            money += A[i]*stock;
            stock = 0;
            price = A[i];
        }
    }
    cout << money << endl;

    return 0;
}