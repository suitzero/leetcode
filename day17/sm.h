
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int x=0,y=0,dir_x=1,dir_y=0,cnt=0,bx_h=n,by_h=n,bx_l=0,by_l=0;
        while(cnt<n*n){
            res[y][x] = ++cnt;
            int tx=x,ty=y;
            tx+=dir_x,ty+=dir_y;
            if(tx>=bx_h) dir_x=0,dir_y=1,by_l++;
            else if(ty>=by_h) dir_x=-1,dir_y=0,bx_h--;
            else if(tx<bx_l) dir_x=0,dir_y=-1,by_h--;
            else if(ty<by_l) dir_x=1,dir_y=0,bx_l++;
            x+=dir_x,y+=dir_y;
        }
        return res;
    }
};
