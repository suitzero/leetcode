#include<iostream>
#include<vector>	

using namespace std;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
      vector<long long> res;
      int hl = intLength / 2;
      long long power_of_ten = 1,limit=1;
      int il = intLength;
      while(il--) limit*=10;
      if(intLength%2==1) hl++;
      while(--hl){ power_of_ten *= 10; }
      long long start_i = power_of_ten;
      for( int j = 0 ; j < queries.size() ; ++j )
      {
        long long i = start_i+queries[j]-1;
        long long pn=i,tmp=i;
        if(intLength%2==1)
        {
          tmp/=10;
        }
        while(tmp && pn < limit)
        {
          pn*=10;
          pn+=tmp%10;
          tmp/=10;
        }
        if( pn >= limit ){
          res.push_back(-1);
        }else res.push_back(pn);
      }
      return res;
    }
};	

int main()
{
	vector<int> input1{1,2,3,4,5,90};
	auto s = Solution();
	vector<long long> output1 = s.kthPalindrome(input1,3);
	for( int i = 0 ; i < output1.size() ; ++i )
	{
		cout << output1[i] << " ";
	}
	cout << endl;
/*
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
	cout << endl; */
}
