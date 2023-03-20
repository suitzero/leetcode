class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> a(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        vector<vector<int>>& o = obstacleGrid;
        for( int i = 0 ; i < m ; ++i ) if(!o[i][0]) a[i][0] = 1; else break;
        for( int i = 0 ; i < n ; ++i ) if(!o[0][i]) a[0][i] = 1; else break; 
        for( int i = 1 ; i < m ; ++i )
        {
            for( int j = 1 ; j < n ; ++j )
            {
                if(!o[i][j]) a[i][j] = a[i-1][j]+a[i][j-1];
            }
        }
        return a[m-1][n-1];
    }
};
