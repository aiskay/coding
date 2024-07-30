#include <iostream>
#include <vector>
using namespace std;


int countWays( int curr, int stairs )
{
    if( curr  > stairs ) return 0;
    if( curr == stairs ) return 1;

    int count = 0;
    count += countWays( curr+1, stairs );
    count += countWays( curr+2, stairs );
    count += countWays( curr+3, stairs );

    return count;
}

int countWaysAns( int n )
{
    if( n < 0 ) return 0;
    else if( n == 0 ) return 1;
    else return countWaysAns(n-1) + countWaysAns(n-2) + countWaysAns(n-3);
}

int countWaysWithMemoHelper( int n, vector<int>& memo )
{
    if( n < 0 ) return 0;
    else if( n == 0 ) return 1;
    else if( memo[n] > -1 ) return memo[n];
    else return memo[n] = countWaysWithMemoHelper( n-1, memo )
                        + countWaysWithMemoHelper( n-2, memo )
                        + countWaysWithMemoHelper( n-3, memo );
}

int countWaysWithMemo( int n )
{
    vector<int> memo( n+1, -1 );
    return countWaysWithMemoHelper( n, memo );
}

int main()
{
    cout << "10 stairs with memo: " << countWaysWithMemo( 35 ) << endl;
    cout << "10 stairs          : " << countWays( 0, 35 ) << endl;
    cout << "10 stairs          : " << countWaysAns( 35 ) << endl;
}