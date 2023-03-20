#include<iostream>
#include<vector>
#include<tuple>
#include<map>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        // [1,-1,1,-1]
        // 1 0 1 0
      vector<int> sum_arr;
      map<int,vector<int>> sum_map;
      int sum =0;
      for( int i = 0 ; i < arr.size() ; ++i )
      {
        sum += arr[i];
        sum_arr.push_back(sum);
        if( sum_map.find(sum) != sum_map.end() ) sum_map[sum].push_back(i);
        else{
          sum_map[sum] = vector<int>{i};
        }
      }
      int s,e;
      for( int i = 0 ; i < arr.size()-2 ; ++i )
      {
        if( sum_map.find(2*sum_arr[i]) != sum_map.end())
        {
          auto tmp = sum_map[2*sum_arr[i]];
          for( int k = 0 ; k < tmp.size() ; ++k )
          {
            if( tmp[k] > i && tmp[k] < arr.size()-1){
              int j = tmp[k];
              if ( sum_arr[i] == sum_arr[j]-sum_arr[i]
                  && sum_arr[i] == sum_arr[sum_arr.size()-1]-sum_arr[j])
              {
                  cout << i << "," << j << endl;
                return true;
              }
            }
          }
        }
      }
      return false;
    }
};

int main()
{
	vector<int> i1{0,2,1,-6,6,-7,9,1,2,0,1};
	auto s = Solution();
	cout << s.canThreePartsEqualSum(i1) << endl;
}
