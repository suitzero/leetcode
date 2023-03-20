#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<tuple>
#include<string>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool myfunction (tuple<TreeNode*,string> i, tuple<TreeNode*,string> j){
	TreeNode *n1,*n2;
	string s1,s2;
	tie(n1,s1) = i;
	tie(n2,s2) = j;
  if(n1->val<n2->val){
	  return true;
	}else if(n1->val == n2->val)
	{
		return lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end());
	}else{
		return false;
	}
}
class Solution {
public:
		string dfs(TreeNode* node){
			if( node != nullptr ){
				string serialize=to_string(node->val);
				serialize.append(dfs(node->left));
				serialize.append(dfs(node->right));
				m_allnodes.push_back(tuple<TreeNode*,string>{node,serialize});
				return serialize;
			}else{
				return "";
			}
		}/*
		bool dfs_comp(TreeNode* node1, TreeNode* node2){
			if( node1 != nullptr && node2 != nullptr ){
				if( node1->val == node2->val ){
					return dfs_comp(node1->left,node2->left) && dfs_comp(node1->right,node2->right);
				}else{
					return false;
			  }
			}else if( node1 == nullptr && node2 == nullptr ){
				return true;
			}else{
				return false;
			}
		}*/
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {		
			vector<TreeNode*> res;
			vector<tuple<TreeNode*,string>> res_2;
			dfs(root);
			sort(m_allnodes.begin(),m_allnodes.end(),myfunction);
			bool flag;
			for(auto i=m_allnodes.begin(); m_allnodes.end() != i ; ++i)
			{
				flag = false;
				TreeNode *n1;
				string s1;
				tie(n1,s1) = *i;
				for(auto j=res_2.rbegin(); res_2.rend() != j ; ++j )
				{
					TreeNode *n2;
					string s2;
					tie(n2,s2) = *j;
					if(n1->val == n2->val && s1.compare(s2))
					{
						flag = true;
						break;	
					}else if(n1->val != n2->val){
						break;
					}
				}
				if( flag ) continue;
				for(auto j=i+1 ; m_allnodes.end() != j ; ++j)
			  {
					TreeNode *n2;
					string s2;
					tie(n2,s2) = *j;
					if(n1->val == n2->val)
					{
						if(s1.compare(s2)){
							res_2.push_back(*i);				
							res.push_back(n1);				
							break;
						}
					}else{
						break;
					}
				}
			}
			return res;
    }
		vector<tuple<TreeNode*,string>>	 m_allnodes;
};

int main()
{
}
