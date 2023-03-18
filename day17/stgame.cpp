#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
			/*vector<int> sumValues;
			int sum = 0;
			for( int i = 0 ; i < stoneValue.size() ; ++i ){
				sum += stoneValue[i];
				sumValues.push_back(sum);
			}*/
			// 1 1 2
			// 0 2 3
			int res=0;
			for( int i = 0 ; i < stoneValue.size() ; ++i ){
				res = max(perm(stoneValue,0,i,stoneValue.size()),res);
			}
			return res;
		}
		
		int perm(vector<int>& stoneValue,int s, int mid, int e){
			int sum_a = 0;
			for( int i = s ; i < mid ; ++i ){
				sum_a += stoneValue[i];
			}

			int sum_b = 0;
			for( int i = mid ; i < e ; ++i ){
				sum_b += stoneValue[i];
			}
			
			int res = 0;

			//cout << "sum:" << sum_a << "," << sum_b << "idx" << s << "," << mid << "," << endl;
			if ( sum_a > sum_b || sum_a == sum_b )
			{
				for( int i = mid ; i < e ; ++i ){
					res = max( sum_b + perm(stoneValue,mid,i,e), res ); 
				}
			}
			if( sum_a < sum_b || sum_a == sum_b )
			{// 0 1 2
				for( int i = s ; i < mid ; ++i ){
					res = max( sum_a + perm(stoneValue,s,i,mid), res ); 
				}
			}
			return res;
		}
};

int main()
{
	vector<int> i1{6,2,3,4,5,5};
	auto s = new Solution();
	cout << s->stoneGameV(i1) << endl;

	vector<int> i2{7,7,7,7,7,7,7};
	cout << s->stoneGameV(i2) << endl;


	vector<int> i3{1,1,2};
	cout << s->stoneGameV(i3) << endl;
}
