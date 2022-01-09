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


struct Node {
    int val, loc;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        Node dq[100001];

        int l = 1, r = 0;
        for (int i = 0; i < k; ++i) {
            int val = nums[i];
            int loc = i;
            while (l <= r && dq[r].val < val)
                r--;
            r++;
            dq[r].val = val;
            dq[r].loc = loc;
        }
        res.push_back(dq[l].val);

		int size = nums.size();
		for (int i = k; i < nums.size(); ++i) {
			int val = nums[i];
            int loc = i;
            
            if (dq[l].loc <= i - k) ++l;
            while (l <= r && dq[r].val < val)
            	r--;
            r++;
            dq[r].val = val;
            dq[r].loc = loc;
            res.push_back(dq[l].val);
		}
		
		return res;
    }
};
