#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void merge_sort(vector<int>& nums,int s,int e){
		if( e-s > 1 ){
			int	mid = s+(e-s)/2;
			merge_sort(nums,s,mid); // 0 2 // 0 1 , 1 2
			merge_sort(nums,mid,e); // 2 4
			static vector<int> temp;
			temp.resize(nums.size());	
			int i1=s,i2=mid,i=0;
			while(i1<mid || i2 < e){
				if( i1 < mid && ( i2 >= e || nums[i1] < nums[i2] ))
					temp[i] = nums[i1++];
				else
					temp[i] = nums[i2++];
				i++;
			}
			int k=e-1;
			i--;
			while(k>=s){
				nums[k--]=temp[i--];
				cout << nums[k+1] << "," << temp[i+1] << " ";
			}
			cout << endl;
		}
	}
  vector<int> sortArray(vector<int>& nums) {
		merge_sort(nums,0,nums.size());
		return nums;
  }
};

int main()
{
	vector<int> a{5,2,3,1};
	auto s = Solution();
	s.sortArray(a);	
	for( int i = 0 ; i < a.size(); ++i )
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
