#include<iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
      int h = find_h_dfs(root,0)-1;
      m_c = 0;
      find_c_dfs(root,0,h);
      m_sc = 0;
      return check_comp_bt(root,0,h);
    }
    int find_h_dfs(TreeNode* node,int lvl)
    {
      if( node == nullptr ) return lvl;
      int max_h = find_h_dfs(node->left,lvl+1);
      max_h = max(find_h_dfs(node->right,lvl+1),max_h);
      return max_h;
    }
    void find_c_dfs(TreeNode* node,int lvl,int target_level)
    {
      if( lvl == target_level ){
        ++m_c;
      }
      if( node == nullptr ) return;
      if( lvl == target_level ){
          m_maxc = max(m_maxc,m_c);
      }
      find_c_dfs(node->left,lvl+1,target_level);
      find_c_dfs(node->right,lvl+1,target_level);
    }
    bool check_comp_bt(TreeNode* node,int lvl,int target_level)
    {
      if( target_level == lvl ) ++m_sc;
      if( node == nullptr && lvl < target_level) return false;
      else if (  node == nullptr && lvl >= target_level ){
        cout << lvl << "," << target_level << "," << m_sc << "," << m_maxc << endl;
        if( lvl == target_level && m_sc <= m_maxc ){

          return false;
        }
        return true;
      }else{
        return check_comp_bt(node->left,lvl+1,target_level)&&check_comp_bt(node->right,lvl+1,target_level);
      }
    }
    int m_c,m_maxc,m_sc;
};
int main()
{
	TreeNode* nodes;
	auto s = Solution();
	s.isCompleteTree(nodes);
}
