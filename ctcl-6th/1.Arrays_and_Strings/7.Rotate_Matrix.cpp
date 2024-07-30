#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


const int N = 4;


int** RotateMatrix( int** matrix )
{
    int** ans = new int* [N];
    for( int i = 0; i < N; ++i ) ans[i] = new int [N]; 

    for( int i = 0; i < N; ++i ){
        for( int j = 0; j < N; ++j ){
            ans[i][j] = matrix[j][i];
        }
    }
    return ans;
}

void printMatrix( int ** matrix )
{
	for ( int i = 0; i < N; ++i ) {
		for( int j = 0; j < N; ++j ) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
    int** matrix = new int* [N];
    for( int i = 0; i < N; ++i ) matrix[i] = new int [N];


    printMatrix( matrix );
    printMatrix( RotateMatrix( matrix ) );

}