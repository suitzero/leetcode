#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr){}
	ListNode(int x, ListNode *next): val(x), next(next){}
};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
	public:
		TreeNode* sortedListToBST(ListNode* head){
			ListNode *node=head;
			while(node){
				vals.push_back(node->val);
				node = node->next;
			}
			return create_btree(0,vals.size());
		}
		TreeNode* create_btree(int s,int e){
			int mid = s+(e-s)/2;	
			TreeNode* node = TreeNode(vals[mid]);
			node->left = create_btree(s,mid);
			node->right = create_btree(mid+1,e);
			return node;
		}
	private:
		vector<int> vals;

};

int main()
{
	ListNode *head = ListNode(-10);
	head->next = ListNode(-3);
	head->next->next = ListNode(0);
	head->next->next->next = ListNode(5);
	head->next->next->next->next = ListNode(9);

	auto s = Solution();
	s->sortedListToBST(head);	
}
