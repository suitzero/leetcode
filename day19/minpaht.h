class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> s(grid.size(),vector<int>(grid[0].size(),0));
        s[0][0]=grid[0][0];
        for( int i = 1 ; i < s.size() ; ++i ) s[i][0] = grid[i][0]+s[i-1][0];
        for( int i = 1 ; i < s[0].size() ; ++i ) s[0][i] = grid[0][i]+s[0][i-1];
        for( int i = 1 ; i < s.size() ; ++i )
        {
            for( int j = 1;  j < s[0].size() ; ++j )
            {
                s[i][j]=grid[i][j]+min(s[i-1][j],s[i][j-1]);
            }
        }
        return s[grid.size()-1][grid[0].size()-1];
    }
};
