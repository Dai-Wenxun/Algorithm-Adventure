class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res(nums.size());
		stack<int> s;
		int size = nums.size();
		for (int i = 2*size-1; i >= 0; --i) {
			while (!s.empty() && s.top() <= nums[i%size])
				s.pop();
			
			if (i < size) {
				res[i] = s.empty() ? -1 : s.top();
 			}
 			s.push(nums[i%size]);
		}
		return res;
    }
};
