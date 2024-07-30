#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;


int** ZeroMatrix( int** matrix, int M, int N )
{
    // ここでは、その行・列が0かどうかを表すために新たに配列を作ったが
    // 1行目, 1列目を代わりに用いることで必要なメモリを削減できる
    bool* isZeroCols = new bool [M];
    bool* isZeroRows = new bool [N];

    for( int i = 0; i < M; ++i ) isZeroCols[i] = false;
    for( int j = 0; j < N; ++j ) isZeroRows[j] = false;

    for( int i = 0; i < M; ++i ){
        for( int j = 0; j < N; ++j ){
            if( matrix[i][j] == 0 )
            {
                isZeroCols[i] = true;
                isZeroRows[j] = true;
            }
        }
    }

    for( int i = 0; i < M; ++i ){
        if( isZeroCols[i] ){
            for( int j = 0; j < N; ++j ) matrix[i][j] = 0;
        }
    }
        
    for( int j = 0; j < N; ++j ){
        if( isZeroRows[j] ){
            for( int i = 0; i < M; ++i ) matrix[i][j] = 0;
        }
    }
    
    return matrix;
}

void printMatrix( int ** matrix, int M, int N )
{
	for ( int i = 0; i < M; ++i ) {
		for( int j = 0; j < N; ++j ) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
    int M = 4, N = 4;
    int** matrix = new int* [M];
    for( int i = 0; i < M; ++i ) matrix[i] = new int [N];

    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand( 0, 9 );
    
    for( int i = 0; i < N; ++i ){
        for( int j = 0; j < N; ++j ){
            matrix[i][j] = rand(mt);
        }
    }

    cout << "Raw matrix: " << endl;
    printMatrix( matrix, M, N );
    cout << endl << "Zero matrix: " << endl;
    printMatrix( ZeroMatrix( matrix, M, N ), M, N );

}