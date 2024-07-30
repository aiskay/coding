#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 後方に文字列が伸びていくときは後ろから編集をすると良い
// 自分で書いた実装; 確かに str.lenth() が for 文中で変化していくので危険な気もする
/*
string URLify( string& str, int true_length )
{
    for( int i = str.length()-1; i >= 0; --i )
    {
        if( str[i] != ' ' )
        {
            str.erase( i+1 );
            break;
        }
    }
    
    for( int i = 0; i < str.length(); ++i )
    {
        if( str[i] == ' ' )
        {
            str.erase( str.begin()+i );
            str.insert( i, "%20" ) ;
        }
    }

    return str;
}
*/

void URLify( string& str, int true_length )
{
    int num_spaces = 0;
    for( int i = 0; i < true_length; ++i )
    {
        if( str[i] == ' ' ) num_spaces++;
    }

    int extended_length = true_length + 2*num_spaces;
    int write_pos = extended_length - 1;
    for( int read_pos = true_length-1; read_pos >=0; --read_pos )
    {
        if( str[read_pos] != ' ' ) str[write_pos--] = str[read_pos];
        else
        {
            str[write_pos--] = '0';
            str[write_pos--] = '2';
            str[write_pos--] = '%';
        }
        
    }
}



int main()
{
    string test_name = "Mr John Smith    ";  // 後ろのバッファは十分確保されている
    cout << " Actual string: \"" << test_name << "\"" << endl;
    URLify( test_name, 13 );
    cout << " URLified string: \"" << test_name << "\"" << endl;
}