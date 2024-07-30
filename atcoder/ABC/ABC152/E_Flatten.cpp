#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

constexpr int MOD = 1e+9 + 7;


// 繰り返し二乗法(Exponentiation by squaring)
// n^8 = ((n^2)^2)^2 を利用する
template <typename T=long long>
T pow_mod(T n, T p, T m)
{
    if( p == 0 ) return 1;
    if( p%2 == 1 ) return pow_mod<T>(n, p-1, m) * n % m;
    else{
        T tmp = pow_mod<T>(n, p/2, m) % m;
        return tmp * tmp % m;
    }
}

// 2 以上 M 以下の素数をエラトステネスの篩を用いて求める, O( n * loglogn )
void calculatePrimeByEratosthenes( int M, std::vector<int>& prime )
{
    std::vector<bool> isPrime( M+1, true );  // isPrime[i]: i が素数かどうか
    isPrime[0] = isPrime[1] = false;
    for( int i = 2; i*i <= M; ++i ){
        if( isPrime[i] ){
            // 素数 i の倍数は素数ではない
            for( int j = 2; i*j <= M; ++j ) isPrime[i*j] = false;
        }
    }
    for( int i = 2; i <= M; ++i ){
        if( isPrime[i] ) prime.push_back( i );
    }
}


int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];


    // LCMを素因数分解した形で求める
    vector<int> prime;
    calculatePrimeByEratosthenes(*max_element(A.begin(), A.end()), prime);

    unordered_map<int, int> index;
    REP(i, N){
        int tmp = A[i];
        for(auto& p: prime){
            // 高速化に必要
            if(tmp == 1) break;
            if(tmp%p != 0) continue;
            int count = 0;
            while(tmp%p == 0){
                tmp /= p;
                ++count;
            }
            index[p] = max(index[p], count);
        }
    }

    // LCMを求める
    long long LCM = 1;
    for(auto idx: index){
        REP(i, idx.second){
            LCM *= idx.first;
            LCM %= MOD;
        }
    }

    // 答えを求める
    long long ans = 0;
    REP(i, N){
        ans += LCM * pow_mod<long long>(A[i], MOD-2, MOD);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}