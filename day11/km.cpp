#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
			int j=0,missing_cnt=0;
			for( int i = 1 ; i < 2001 ; ++i )
			{
				if( j < arr.size() && i == arr[j] ){
			  	++j;		
				}else{
					if(++missing_cnt==k){
						return i;
					}
				}
			}
			return -1;
	}
};

int main()
{
	vector<int> i1{2,3,4,7,11};
	auto s = Solution();
	cout << s.findKthPositive(i1,5) << endl;
}
