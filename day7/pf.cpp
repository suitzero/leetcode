#include<iostream>
#include<vector>	

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        char last_char=chars[0]-1;
        int char_cnt = 0;
        int i,j;
        for( i=0,j=0 ; j < chars.size()+1 ; ++j )
        {
          if ( j < chars.size() && chars[j] == last_char ){
            ++char_cnt;
          }else{
              if( j > 0 ){
                chars[i++]=last_char;
                if(char_cnt>1){
                  int power_of_ten=1;
                  // 1023
                  while(char_cnt/(power_of_ten*10)) power_of_ten *= 10;
                  while(power_of_ten > 0){
                    chars[i++] = '0'+char_cnt/power_of_ten;
                    cout << i << "," << chars.size() << chars[i-1] << endl;
                    char_cnt=char_cnt%power_of_ten;
                    power_of_ten /= 10;
                  }
                }
              }
              if ( j < chars.size() ) last_char = chars[j];
              char_cnt = 1;
          }
        }
        return i;
    }
};

int main()
{
	vector<char> input1{'a','a','b','b','c','c','c'};
	auto s = Solution();
	cout << s.compress(input1) << endl;
	for( int i = 0 ; i < input1.size() ; ++i )
	{
		cout << input1[i];
	}

	vector<char> input2{'a'};
	cout << s.compress(input2) << endl;
	for( int i = 0 ; i < input2.size() ; ++i )
	{
		cout << input2[i];
	}
	cout << endl;

	vector<char> input3{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	cout << s.compress(input3) << endl;
	for( int i = 0 ; i < input3.size() ; ++i )
	{
		cout << input3[i];
	}
	cout << endl;
}
