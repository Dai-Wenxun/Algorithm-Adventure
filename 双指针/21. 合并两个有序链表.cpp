class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1), *p = dummy;
		ListNode *p1 = l1, *p2 = l2;
		
		while(p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) {
				p->next = p1;
				p1 = p1->next;
			} else {
				p->next = p2;
				p2 = p2->next;
			}
			p = p->next;
		}
		
		if (p1 != NULL) {
			p->next = p1;
		}
		
		if (p2 != NULL) {
			p->next = p2;
		}
		return dummy->next;
    }
};
