#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
	public:
	    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		    map<int,int> m;
			for( int i = 0 ; i < nums.size(); ++i ){ 
				if( m.find(nums[i]) != m.end())
				{
			        	if( i-m[nums[i]]  <= k ) return true;
				}
				m[nums[i]] = i;
			}
	    return false;
	}
};

int main(){
	auto s = Solution();

	vector<int> ex1={1,2,3,1};
	cout << "ex1:" << s.containsNearbyDuplicate(ex1,3) << endl;

	vector<int> ex2={1,0,1,1};
	cout << "ex2:" << s.containsNearbyDuplicate(ex2,1) << endl;


	vector<int> ex3={1,2,3,1,2,3};
	cout << "ex3:" << s.containsNearbyDuplicate(ex3,2) << endl;
	return 0;
}
