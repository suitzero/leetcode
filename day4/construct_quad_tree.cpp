#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// grid [[0,1],[1,0]]

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
0 1
1 0
*/

class Solution {
public:
    bool isAlltheSame(vector<vector<int>>& grid,int sx,int sy,int ex,int ey){
        int val = grid[sx][sy];
        for( int i = sy ; i < ey  ; ++i )
        {
                for( int j = sx ; j < ex; ++j )
                {
                        if( val != grid[i][j] )
                        {
                                return false;
                        }
                }
        }
        return true;
    }
    Node* construct(vector<vector<int>>& grid) {
        cout << "construct" << endl;
        Node* node = new Node();
        vector<vector<unsigned long>> range{
                {0,0,grid.size()/2,grid.size()/2},
                {grid.size()/2,0,grid.size(),grid.size()/2},
                {0,grid.size()/2,grid.size()/2,grid.size()},
                {grid.size()/2,grid.size()/2,grid.size(),grid.size()}
        };

        int sx,sy,ex,ey;
        for ( int i=0 ; i < 4 ; ++i )
        {
                Node* child_node = new Node();
                sx = range[i][0]; sy = range[i][1];
                ex = range[i][2]; ey = range[i][3];
                cout << sx << ","<< sy<< "," << ex << ","<< ey <<endl;
                if(isAlltheSame(grid,sx,sy,ex,ey))
                {
                    child_node->val = grid[0][0];
                    child_node->isLeaf = true;
                }else{
                        vector<vector<int>> sub_grid;
                        for( int i = sy ; i < ey ; ++i )
                        {
                                auto row = vector<int>();
                                for( int j = sx ; j < ex ; ++j )
                                {
                                        row.push_back(grid[i][j]);
                                }
                                sub_grid.push_back(row);
                        }
                        child_node = construct(sub_grid);
                }

                switch(i){
                case 1:
                    node->topLeft = child_node;
                    break;
                case 2:
                    node->topRight = child_node;
                    break;
                case 3:
                    node->bottomLeft = child_node;
                    break;
                case 4:
                    node->bottomRight = child_node;
                    break;
                }
        }
        return node;
    }
};

int main(){
	auto s = Solution();

	vector<vector<int>> ex1{{0,1},{1,0}};
	cout << "ex1:" << s.construct(ex1) << endl;
	vector<vector<int>> ex2{{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
	
	cout << "ex2:" << s.construct(ex2) << endl;
	return 0;
}
