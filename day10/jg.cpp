#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        vector<int> dp;
        for( int i = 0 ; i < arr.size() ; ++i )
        {
            dp.push_back(1e5);
        }
        map<int,int> j;
        dp[arr.size()-1] = 0;
        for( int i = arr.size()-1 ; i >= 0 ; --i ){
            int m=dp[i];
            if ( i+1 < arr.size() )
              m = min(m,dp[i+1]+1);
            if ( i-1 > 0 )
              m = min(m,dp[i-1]+1);
            if ( j.find(arr[i]) != j.end()){
              m = min(m,j[arr[i]]+1);
            }else{
              j[arr[i]] = m;
            }
            dp[i] = min(dp[i],m);
            j[arr[i]] = min(j[arr[i]],m);
						for( int k = 1 ; i+k < arr.size() ; ++k ){
							if ( m+k < j[arr[i+k]]) j[arr[i+k]]=m+k;
							else break;
						}
        }
        return dp[0];
    }
};

int main()
{
	vector<int> i1{100,-23,-23,404,100,23,23,23,3,404}; 
	auto s = Solution();
	// 
	cout << s.minJumps(i1) << endl; 	

	vector<int> i2{11,22,7,7,7,7,7,7,7,22,13};
	cout << s.minJumps(i2) << endl; 	

	vector<int> i3{-95,100,-86,50,99,50,99,43,-86,43,-26,-7,-19,-1,50,99,100,-1,-27,2,-69,60,-1,21,-54,43,-94,-94,-7,67,50,57,-27,60,-19,-7,67,-19,-7,99,-69,-69,100,-95,-94,2,100,50,50,-19,-21,-19,60,-19,-95,-21,67,-1,57,50,50,-27,-94,50,99,-7,-21,-21,57,-95,57,-69,100,-7,-86,-31,-77,21,-95,-1,-54,57,-94,-27,-95,-54,2,21,50,-21,2,-7,9,100,9,-95,-73,-77,99,-54};

	cout << s.minJumps(i3) << endl; 	

	vector<int> i4{1,3,1,1,1,1,1,1,1,12,1};
	cout << s.minJumps(i4) << endl; 	
}
