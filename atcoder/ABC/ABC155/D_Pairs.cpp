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
    vector<long long> Am, Az, Ap;
    REP(i, N){
        long long A;
        cin >> A;
        if(A <  0) Am.push_back(A);
        if(A == 0) Az.push_back(A);
        if(A >  0) Ap.push_back(A);
    }

    sort(Am.begin(), Am.end());
    sort(Az.begin(), Az.end());
    sort(Ap.begin(), Ap.end());

    long long m_cases = Am.size()*Ap.size();
    long long z_cases = N*(N-1)/2 - (N-Az.size())*(N-Az.size()-1)/2;

    if(K <= m_cases){

    }
    else if(K <= m_cases+z_cases) cout << 0 << endl;
    else{

    }

    return 0;
}