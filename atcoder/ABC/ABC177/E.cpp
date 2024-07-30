#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

// Greatest Common Multiple (GCD)
// 2数の最大公約数 by ユークリッド互助法
template <typename T=long long>
T gcd(T a, T b)
{
    if(b == 0) return a;
    else return gcd<T>(b, a % b);
}

// 3数以上の最大公約数
// a, b, c の最小公約数は a, b の最小公約数と c の最小公約数に等しいことを利用
template <typename T=long long>
T gcd(std::vector<T>& a, int i = 0)  // a[i] と a[i+1] ~ a[end] の最大公約数を返す
{
    if(a.size() < 2) return 0;  // 必要に応じて変える
    if(i == (int) a.size() - 2) return gcd<T>(a[i], a[i+1]);
    return gcd<T>(a[i], gcd(a, i+1));
}


// Least Common Multiple (LCM)
// 2数の最小公倍数
template <typename T=long long>
T lcm(T a, T b) {return a * b / gcd<T>( a, b );}

// 3数以上の最小公倍数
template <typename T=long long>
T lcm(std::vector<T>& a, int i = 0)  // a[i] と a[i+1] ~ a[end] の最小公倍数を返す
{
    if(a.size() < 2) return 0;  // 必要に応じて変える
    if(i == (int) a.size() - 2) return lcm<T>(a[i], a[i+1]);
    return lcm(a[i], lcm<T>(a, i+1));
}

// 2 以上 M 以下の素数をエラトステネスの篩を用いて求める, O( n * loglogn )
void calculatePrimeByEratosthenes( int M, std::vector<long long>& prime )
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

bool check(vector<long long>& A, int N){
    vector<long long> prime;
    calculatePrimeByEratosthenes(1e+4, prime);

    vector<bool> is_appeared(1e+6+1, false);
    REP(i, N){
        long long tmp = A[i];
        for(auto p: prime){
            if(tmp == 1) continue;
            if(p*p > A[i]){
                if(is_appeared[tmp]) return false;
                is_appeared[tmp] = true;
                break;
            }
            if(tmp%p == 0){
                if(is_appeared[p]) return false;
                is_appeared[p] = true;
                while(tmp%p == 0) tmp /= p;
            }
        }
    }
    return true;
}


int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    REP(i, N) cin >> A[i];

    if(gcd<long long>(A) == 1){
        if(check(A, N)) cout << "pairwise coprime" << endl;
        else cout << "setwise coprime" << endl;
    }else cout << "not coprime" << endl;

    return 0;
}