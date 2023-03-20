#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
			int total = 0;
			int max_num = 0;
			for( int i = 0 ; i < piles.size() ; ++i )
			{
				total += piles[i];
				max_num = max(piles[i],max_num);
			}
			int min_num = ceil((double)total/h);
			int s=min_num,e=max_num;		
			cout << max_num << endl;
			auto validate = [piles,h](int num) {
				int total_h = 0;
				for( int i = 0 ; i < piles.size() ; ++i )
				{
					total_h += ceil((double)piles[i]/num);
				}
		//		cout << (double)1000000000 / 999999968 << endl;
		//		cout << num << " " << total_h << ","<< h << endl;
				if( total_h <= h ) return true;
				else return false;
			};

			if(validate(s)){
				return s;
			}
			//cout << "s" << s << endl;
			int res = max_num;
			cout << res << endl;
			while(s<e){
				int mid = s+(e-s)/2;
				//cout << s  << "," << e << "," << mid << endl;
				if(validate(mid)){
					res = min(res,mid);
					e = mid;
				}else{
					s = mid+1;
				}
			}
			return res;
	}
};

int main()
{
	auto s = Solution();
	vector<int> i1{3,6,7,11};
	vector<int> i2{30,11,23,4,20};
	vector<int> i3{1000000000,1000000000};
/*	cout << s.minEatingSpeed(i1,8) << endl;
	cout << s.minEatingSpeed(i2 ,5) << endl;
	cout << s.minEatingSpeed(i2 ,6) << endl;*/
	cout << s.minEatingSpeed(i3 ,3) << endl;
}
