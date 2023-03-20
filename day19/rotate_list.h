class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode *node=head,*prev=nullptr,*new_head=nullptr;
        while(node)
        {
            node = node->next;
            ++n;
        }
        if(n == 0) return head;
        int target = (n-(k%n))%n;
        node = head;
        while(node && target--){
            prev = node;
            node = node->next;
        }
        if( prev ) prev->next = nullptr;
        new_head = node;
        if(new_head == head) return new_head;
        while(node && node->next){
            node = node->next;
        }
        node->next = head;
        return new_head;
    }
};
