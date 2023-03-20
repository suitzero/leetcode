#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
			vector<int> res;
			queue<vector<int>> q;
			q.push({0,0});
			while(!q.empty()){
				auto cur = q.front(); q.pop();
				int r=cur[0],c=cur[1];
				cout << nums[r][c] << " ";
				res.push_back(nums[r][c]);
				if( c == 0 && r+1 < nums.size() ){
					q.push({r+1,c});
				}
				if( c+1 < nums[r].size() ){
					q.push({r,c+1});
				}
			}
			return res;
		}
};

int main()
{
	vector<vector<int>> i1 = {{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> i2 = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
	vector<vector<int>> i3 = {{14,12,19,16,9},{13,14,15,8,11},{11,13,1}};
	
	auto s = Solution();
	auto o1 = s.findDiagonalOrder(i1);
	for( auto i : o1 ) cout << i << " ";
	cout << endl;

	auto o2 = s.findDiagonalOrder(i2);
	for( auto i : o2 ) cout << i << " ";
	cout << endl;

	auto o3= s.findDiagonalOrder(i3);
	for( auto i : o3 ) cout << i << " ";
	cout << endl;
}
