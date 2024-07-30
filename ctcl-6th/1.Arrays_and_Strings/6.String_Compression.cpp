#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 自分の実装
string StringCompression( string& str )
{
    string ans( 1, str[0] );
    for( int i = 1; i < str.length(); ++i )
    {
        int num_same_char = 0;
        bool isFirstAppeared = true;

        if( str[i-1] != str[i] ) str.push_back( str[i] );
        else if( str[i] == str[i-1] && isFirstAppeared )
        {
            ans.push_back( str[i] );
            num_same_char++;
            isFirstAppeared = false;
        }
        else if( str[i] == str[i-1] &&  !isFirstAppeared )
        {
            ans.push_back( num_same_char );
        }
        

    }
    
    if( ans.length() < str.length() ) return ans;
    else return str;
}

string compress( string str)
{
	size_t original_length = str.length();
	if( original_length <= 2 ) return str;

	string compressed_str{""};
	int count = 1;
	for( size_t i = 1; i < original_length; ++i ) {
		if( str[i-1] == str[i] ) ++count;
		else
        {
			compressed_str += str[i-1];
			compressed_str += to_string(count);  // 数値を string に変換
			count = 1;
		}
	}
	compressed_str += str[original_length-1];
	compressed_str += to_string(count);

	if( compressed_str.length() >= original_length ) return str;
	else return compressed_str;
}



int main()
{
    vector<string> str = { "aabccccaaa", "aabcd" };
    for( auto s: str )
	    cout << s << " -> " << compress( s ) << endl;
}