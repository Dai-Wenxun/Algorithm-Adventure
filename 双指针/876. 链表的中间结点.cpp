class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p1 = head, *p2 = head->next;
		
		while(p2 != NULL) {
			p1 = p1->next;
			for (int i = 0; i < 2; ++i) 
				if (p2 != NULL)
					p2 = p2->next;
		}
	
		return p1;
    }
};
