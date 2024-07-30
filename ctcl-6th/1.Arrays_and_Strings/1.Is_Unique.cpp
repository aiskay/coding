#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 文字数が 2^7 = 128 種類のASCIIコードを仮定

bool isUniqueChars( const string& str )
{
    if( str.length() > 128 ) return false;

    vector<bool> char_set(128);
    for( int i = 0; i < str.length(); ++i )
    {
        int val = str[i];
        if( char_set[val] == true ) return false;
        char_set[val] = true;
    }
    return true;
}

// bit演算を用いることでメモリを 1/8 に減らせる
// * bool型は 1 Byte( 8 bit ) であるため
bool isUniqueCharsBitset( const string& str )
{
    if( str.length() > 128 ) return false;

    bitset<256> bits;  // 256 bit のビット配列 bits を0で初期化
    for( int i = 0; i < str.length(); ++i )
    {
        int val = str[i];
        if( bits.test(val) == true ) return false;
        bits.set(val); // val bit 目を true にする
                       // bits.set( val, true ), bits[val] = true
                       // という書き方も可能
    }
    return true;
}

// bit 演算を持ちいた実装
bool isUniqueCharsBit( const string& str )
{
    if( str.length() > 128 ) return false;

    int checker = 0;
    for( int i = 0; i < str.length(); ++i )
    {
        int val = str[i];
        if( ( checker & 1<<val) > 0 ) return false;
        checker |= ( 1 << val );  // |= で代入だが、=でも良さそう
    }
    return true;
}


int main()
{
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
		}
		cout <<endl << "Using bit vector" <<endl;
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueCharsBitset(word) <<endl;
		}
		cout <<endl << "Using no Data Structures" <<endl;
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueCharsBit(word) <<endl;
		}
}