class Solution {
public:
    bool hasCycle(ListNode *head) {
    	if (head == nullptr || head->next == nullptr)
			return false; 
    	
    	ListNode *p1 = head, *p2 = head->next;
		
		while(1) {
			for (int i = 0; i < 2; ++i) {
				if (p2 == p1)
					return true;
				if (p2 == nullptr)
					return false; 
				p2 = p2->next;
			}
			p1 = p1->next;		
		}
    }
};
