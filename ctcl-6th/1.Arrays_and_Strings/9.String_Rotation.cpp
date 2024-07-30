#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

// 文字列 s1 = x + y と s2 = y + x は
// どちらも s1 + s1 = x + y + x + y のsubstringであることを用いる
bool isSubstring( const string& s1, const string& s2 )
{
    if( s1.length() == 0 || s1.length() != s2.length() ) return false;
    
    string s_concat = s1 + s1;  // concatonate: つなぐ
    
    // find( s ) は部分文字列 s を探し、見つからなかったとき std::string::npos を返す
    if( s_concat.find( s2 ) != string::npos ) return true;
    else return false;
}


int main()
{
    string str1 = "waterbottle";
    string str2 = "erbottlewat";

    cout << str2 << " is";
    if( !isSubstring( str1, str2 ) ) cout << " not";
    cout << " substring of " << str1 << endl;
}