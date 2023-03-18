class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        function<void(vector<int>&,int,int,int)> perm = [&](vector<int>& arr, int target, int sum, int index_start){
            for( int i = index_start ; i < candidates.size() ; ++i )
            {
                if ( sum+candidates[i] < target)
                {
                    arr.push_back(candidates[i]);
                    perm(arr,target,sum+candidates[i],i);
                    arr.pop_back();
                }else if(sum+candidates[i] == target)
                {
                    arr.push_back(candidates[i]);
                    vector<int> el;
                    el.assign(arr.begin(),arr.end());
                    arr.pop_back();
                    res.push_back(el);
                }
            }
        };
        vector<int> arry;
        perm(arry,target,0,0);
        return res;
    }
};
