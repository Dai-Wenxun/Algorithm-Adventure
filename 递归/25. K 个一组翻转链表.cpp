class Solution {
public:
	
	ListNode* reverseKGroup(ListNode* head, int k) {
		head = new ListNode(-1, head);
		
		ListNode *p1 = head, *p2 = head->next, *p3 = head->next;
		
		while(1) {
			for (int i = 0; i < k; ++i) {
				if (p3 == NULL) {
					return head->next;
				} else {
					p3 = p3->next;
				}
			}
			
			p2 = reverseN(p1->next, k);
			p1->next = p2;
			for (int i = 0; i < k; ++i)
				p1 = p1->next; 
			p2 = p3;
		}
		
		return head->next;	
    }
    
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *p1 = head, *p2 = head;
		
		for (int i = 0; i < k; ++i) {
			if (p2 == NULL) {
				return head;
			} else {
				p2 = p2->next;
			}
		}
		
		head = reverseN(head, k);
		p1->next = reverseKGroup(p1->next, k);
		
		return head;
    }
	
	ListNode *successor;
	ListNode *reverseN(ListNode *head, int n) {
		if (n == 1) {
			successor = head->next;
			return head;
		}
		
		ListNode *last = reverseN(head->next, n-1);
		head->next->next = head;
		head->next = successor;
		
		return last;
	} 
};
