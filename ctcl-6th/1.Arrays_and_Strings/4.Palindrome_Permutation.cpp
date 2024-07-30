#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


void countFrequency( const string& str, vector<int>& frequency )
{
    for( auto str_char: str  )
    {
        if( str_char != ' ' ){
            if( 'a' <= str_char && str_char <= 'z' ) frequency[str_char-'a']++;
            if( 'A' <= str_char && str_char <= 'Z' ) frequency[str_char-'A']++;
        }
    }
}

// 文字数を数える実装
bool isPalindromePermutationCount( const string& str )
{
    vector<int> frequency(26);  // 大文字小文字を区別しないalphabetなので26でよい
    countFrequency( str, frequency );
    
    // 文字列の長さの偶奇に関わらず、2つ以上の奇数を持つ場合に false を返す関数を書けば良い
    // なぜなら、偶数長の文字列の場合、奇数個の文字が1つだけであることはありえないから
    bool oddAppeared = false;
    for ( int i = 0 ; i < 26; ++i )
    {
        if      ( frequency[i] % 2  && oddAppeared ) return false;
        else if ( frequency[i] % 2 && !oddAppeared ) oddAppeared = true;
    }

    return true;
}

// for 文1回で判定する実装
bool isPalindromePermutationCount2( const string& str )
{
    vector<int> frequency(26);
    int odd_count = 0;

    for ( auto c: str )
    {
        if( c != ' ' ){
            int idx;
            if( 'a' <= c && c <= 'z' ) idx = c-'a';
            if( 'A' <= c && c <= 'Z' ) idx = c-'A';
            frequency[idx]++;
            if( frequency[idx] % 2 != 0 ) odd_count++;
            else odd_count--;
        }
    }
    return (odd_count <= 1);
}

// bit をflipすることで簡易なコードで計算できる


int main()
{
    vector<string> test = { "Taco cat", "abn" };
    for( auto name: test )
    {
        cout << boolalpha << isPalindromePermutationCount2( name ) << endl;
    }
}