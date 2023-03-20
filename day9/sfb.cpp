#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
			long long cnt = 0,cntj=0;

			int min_n=INT_MAX,max_n=INT_MIN;
			int min_n_cnt=0,max_n_cnt=0;
			int l=0,r=0;
			while(l<=r){
				min_n = min(nums[r],min_n);
				max_n = min(nums[r],max_n);
				min_n=INT_MAX;max_n=INT_MIN;
				min_n_cnt=0;max_n_cnt=0;
				cntj = 0;
				while(min_n == minK && max_n == maxK) 
				{
					if(nums[r] == minK) ++min_n_cnt;
					if(nums[r] == maxK) ++max_n_cnt;
					++cntj;
					++r;
					min_n = min(nums[r],min_n);
					max_n = min(nums[r],max_n);
				}
				cnt += cntj;
				while(cntj > 0 && min_n_cnt > 0 && max_n_cnt > 0)
				{
					if (nums[l] == min_n) --min_n_cnt;
					if (nums[l] == max_n) --max_n_cnt;
					++l;
					++cnt;
				}
			}

				
			/*
			for( int i = 0 ; i < nums.size() ; ++i )
			{
				if( i>0 && cntj > 0 && (nums[i-1] != min_n && nums[i-1] != max_n
					|| (nums[i-1] == min_n && --min_n_cnt > 0)
					|| (nums[i-1] == max_n && --max_n_cnt > 0)))
				{
					cout << i << "," << cnt << "," << cntj << "," << min_n_cnt << "," << max_n_cnt << endl;
					cnt += --cntj;
				}else{
					min_n=INT_MAX;max_n=INT_MIN;
					min_n_cnt=0;max_n_cnt=0;
					cntj = 0;
					for( int j = i ; j < nums.size(); ++j )
					{
						min_n = min(nums[j],min_n);
						max_n = max(nums[j],max_n);
						if(min_n < minK || max_n > maxK)  break;
						if(min_n == minK && max_n == maxK) ++cntj;	
						if(nums[j] == minK) ++min_n_cnt;
						if(nums[j] == maxK) ++max_n_cnt;
					}
					cnt += cntj;
				}	
			}*/
			return cnt;
    }
};

int main()
{
	vector<int> i1{1,3,5,2,7,5};
	auto s = Solution();
	//cout << s.countSubarrays(i1,1,5) << endl;

	vector<int> i2;
	for( int i = 0 ; i < 100000 ; ++i )
		i2.push_back(1);
	
	//cout << s.countSubarrays(i2,1,1) << endl;

//	vector<int> i3{35054,398719,945315,945315,820417,945315,35054,945315,171832,945315,35054,109750,790964,441974,552913};
	vector<int> i3{1,3,1,5,2,7,5};
	cout << s.countSubarrays(i3,1,5) << endl;
}
