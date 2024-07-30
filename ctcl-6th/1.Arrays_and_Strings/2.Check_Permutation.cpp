#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// sort を用いた実装
bool arePermutationSort( string& str1, string& str2 )
{
    if( str1.length() != str2.length() ) return false;
    
    sort( str1.begin(), str1.end() );
    sort( str2.begin(), str2.end() );

    for( int i = 0; i < str1.length(); ++i )
    {
        if( str1[i] != str2[i] ) return false;
    }

    return true;
}

// 逐次的に数える実装
bool arePermutationCount( const string& str1, const string& str2 )
{
    if( str1.length() != str2.length() ) return false;
    
    vector<int> count( 256 );
    for( int i = 0; i < str1.length(); ++i ) count[str1[i]]++;
    for( int i = 0; i < str2.length(); ++i )
    {
        int val = str2[i];
        count[val]--;
        if( count[val] < 0 ) return false;
    }
    return true;
}


int main()
{
    // Test Method 1; Using sort
    cout << "Method 1; Using sort" << endl;
    string str1 = "testest";
    string str2 = "estxest";
    if( arePermutationSort(str1, str2) )
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
    if( arePermutationSort(str1, str2) )
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;

    //Test Method 2; Using character count
    cout << "Method 2; Using character count" << endl;
    str1 = "testest";
    str2 = "estxest";
    if( arePermutationCount(str1, str2) )
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
     if( arePermutationCount(str1, str2) )
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
}