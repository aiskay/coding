#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 自分の実装
// 現れたアルファベットの差分の個数を数えて、それが -1, 1 以外なら false を返す
bool isOneAway( string& str1, string& str2 )
{
    vector<int> count(26);
    for( auto c: str1 ) count[c-'a']++;
    for( auto c: str2 ) count[c-'a']--;
    bool isAppeared = false;  // -1, 1 が現れたかどうか
    for( auto c: count )
    {
        if( (c == -1 || c == 1) && isAppeared ) return false;
        else if( c == -1 || c == 1 ) isAppeared = true;
    }
    return true;
}

// 模範解答
/*
bool isOneAway(string s1, string s2)
{
	string a = s1.length() >= s2.length() ? s1 : s2;  // s1, s2 の内長い方
	string b = s1.length() < s2.length() ? s1 : s2;   // s1, s2 の内短い方
	
	int len1 = a.length();
	int len2 = b.length();

	if( abs(len1-len2)>1 ) return false;
	
	bool isDifference = false;
	for( int i=0, j=0; i<len1 && j<len2; )
    {
		if( a[i] != b[j] )
        {
			if( isDifference ) return false;
			isDifference = true;
			if( len1 == len2 ) i++,j++;  // 置き換えの場合
			else i++;                    // 挿入、削除の場合
		}
		else i++,j++;
	}
	return true;
}
*/


int main()
{
    string str1 = "pales", str2 = "ple";
	cout << str1 << ", " << str2 << " -> " << boolalpha << isOneAway(str1,str2) << endl;
}