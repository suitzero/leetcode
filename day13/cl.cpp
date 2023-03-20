#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

struct ListNode {
	 int val;
	 ListNode *next;
	    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
 ListNode *detectCycle(ListNode *head) {
 	unordered_map<ListNode*,bool> m;
	
	auto dfs=[&](ListNode* node){
		if ( m.find(node) != m.end() )
		{
			return node;
		}else{
			m[node] = true;
			dfs(node->next);
		}
	};
	return dfs(head);
}
};

int main()
{
	cout << -1%3 << endl;
}

