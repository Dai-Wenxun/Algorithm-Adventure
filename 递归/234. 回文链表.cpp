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
