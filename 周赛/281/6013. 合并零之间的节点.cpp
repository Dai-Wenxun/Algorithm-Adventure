class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
    	ListNode* p = head;
    	
    	while (p != nullptr && p->next != nullptr) {
    		if (p->next->val != 0) {
    			ListNode * node = new ListNode();
    			ListNode * prev = p;
    			
    			while (p->next->val != 0) {
    				p = p->next;
    				node->val += p->val;
				}
				
				prev->next = node;
				node->next = p->next;
				p = node;
			} else {
				p->next = p->next->next;
			}
		}
    	
    	return head->next;
    }
};
