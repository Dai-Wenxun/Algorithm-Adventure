class Solution {
public:
	ListNode *left;
    bool isPalindrome(ListNode* head) {
		left = head;
		return traverse(head);
    }
    bool traverse(ListNode *right) {
		if (right == NULL) return true;
		
		bool res = traverse(right->next);
		
		res = res && (left->val == right->val);
		
		left = left->next;
		
		return res;
	} 
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if (head->next == NULL)
    		return true;
    	
		ListNode *p1, *p2;
		p1 = p2 = head;
					
		while(p2 != NULL && p2->next != NULL) {
			p1 = p1->next;
			p2 = p2->next->next;
		}
		
		if (p2 != NULL)
			p1 = p1->next;
		
		
		ListNode *last = reverse(p1);
		
		while(last != NULL) {
			if (head->val != last->val)
				return false;
			head = head->next;
			last = last->next;
		}
		
		return true;	
	}
	
	ListNode *reverse(ListNode *head) {
		ListNode *pre = NULL, *cur = head;
		
		while(cur != NULL) {
			ListNode *nxt = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nxt;
		}
		
		return pre;
	}
};
