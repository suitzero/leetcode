#include<iostream>
#include<random>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x) , next(next) {}
};

class Solution {
public:
    Solution(ListNode* head): head(head){
			int i=0;
			ListNode* node=head;
			while( node != nullptr )
			{
				node = node->next;
				i+=1;
			}
			m_node_cnt = i;
			cout << m_node_cnt << endl;
			m_distribution = new uniform_int_distribution<int>(1,m_node_cnt);
}

int getRandom() {
	int index = m_distribution->operator()(m_generator);
	return getVal(index);
}

private:
	int getVal(int idx)	{
		int i = 1;
		ListNode* node=head;
		while( i < idx )
		{
			node = node->next;
			i+=1;
		}
		return node->val;
	}
	ListNode* head;
	int m_node_cnt;
  std::default_random_engine m_generator;
	uniform_int_distribution<int> *m_distribution;
};

int main()
{
	ListNode* a = new ListNode();
	a->val = 1;
	a->next = new ListNode();
	a->next->val = 2;
	a->next->next = new ListNode();
	a->next->next->val = 3;
	auto s = Solution(a);
	cout << s.getRandom() << endl;

	cout << s.getRandom() << endl;
	cout << s.getRandom() << endl;
	cout << s.getRandom() << endl;
	cout << s.getRandom() << endl;
	cout << s.getRandom() << endl;
	cout << s.getRandom() << endl;
}
