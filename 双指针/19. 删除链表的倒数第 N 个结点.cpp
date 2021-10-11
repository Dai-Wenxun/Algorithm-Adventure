class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head->next == NULL)
			return NULL;
		
		ListNode *p1 = head, *p2 = head;
		for (int i = 0; i < n; ++i) {
			p1 = p1->next; 
			if (p1 == NULL)
				return head->next;
		}
		
		
		while(p1->next != NULL) {
			p1 = p1->next;
			p2 = p2->next;
		}
		
		p2->next = p2->next->next;
		
		return head;
    }
};
