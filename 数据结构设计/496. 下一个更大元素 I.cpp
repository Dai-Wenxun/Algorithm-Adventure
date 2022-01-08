class Solution {
public:
	vector<int> mp = vector<int>(10001, 0);
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> s;
		for (int i = nums2.size()-1; i >= 0; --i) {
			while (!s.empty() && s.top() < nums2[i])
				s.pop();
				
			mp[nums2[i]] = s.empty() ? -1 : s.top();
			s.push(nums2[i]);
		} 
		
		vector<int> res(nums1.size());
		for (int i = 0; i < nums1.size(); ++i) {
			res[i] = mp[nums1[i]];
		}
		return res;
    }
};
