struct func {
	bool operator() (ListNode *p1, ListNode *p2) {
		return p1->val > p2->val;
	}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode *>, func> q;
		
		for (ListNode *p: lists) {
			while(p != NULL) {
				q.push(p);	
				p = p->next;
			}
		}
		
		ListNode *head = new ListNode(-1), *ptr = head;
		
		while(!q.empty()) {
			ptr->next = q.top();
			q.pop();
			ptr = ptr->next;
		}
        ptr->next = NULL;
 		return head->next;
	}
};
