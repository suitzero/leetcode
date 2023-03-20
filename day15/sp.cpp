#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
			int cnt = 0;
			for( int i = 0 ; i < nums.size() ; ++i )
			{
				for( int j = i+1; j < nums.size() ; ++j )
				{
					if (nums[i]+nums[j] == target) ++cnt;
				}
			}
		 	return cnt*2; 
	}
};
							
int main()
{
}
