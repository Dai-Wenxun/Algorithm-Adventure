class MonotonicQueue {
public:
	list<int> q;
	
	void push(int n) {
		while (!q.empty() && q.back() < n)
			q.pop_back();
		q.push_back(n); 
	}
	
	int max() {
		return q.front();
	}
	
	void pop(int n) {
		if (n == q.front())
			q.pop_front();
	}
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 1)
			return nums;
			
		vector<int> res;
		MonotonicQueue mq; 
		
		for (int i = 0; i < nums.size(); ++i) {
			if (i < k-1) {
				mq.push(nums[i]);
			} else {
				mq.push(nums[i]);
				
				res.push_back(mq.max());
				
				mq.pop(nums[i-k+1]);
			}
		}
		return res;
    }
};
