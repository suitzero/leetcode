#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
			int res = 0;
			for( auto s : strs ){
				bool isDigit = true;
				for( int i = 0 ; i < s.length() ; ++i )
				{
					if( !(s[i] >= '0' && s[i] <= '9') ){
						isDigit = false;	
						cout << s[i] << endl;
						break;
					}			
				}

				if (!isDigit){
					res = max(res,(int)s.length());
				}else{
					res = max(res,stoi(s));
				}
			}
			return res;
	}
};

int main()
{
	vector<string> i1{"alic3","bob","3","4","00000"};
	vector<string> i2{"1","01","001","0001"};
	vector<string> i3{"kzgy","0qgl3","4","khzv","jtglz","85b","47","jf","8i0a","oy"};
	auto s = Solution();
	cout << s.maximumValue(i1) << endl;
	cout << s.maximumValue(i2) << endl;
	cout << s.maximumValue(i3) << endl;
}

