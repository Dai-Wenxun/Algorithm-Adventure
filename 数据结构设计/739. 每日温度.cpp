class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tps) {
		vector<int> res(temperatures.size());
		stack<int> s; 
		
		for (int i = tps.size()-1; i >= 0; --i) {
			while (!s.empty() && tps[s.top()] <= tps[i]) 
				s.pop();
			
			res[i] = s.empty() ? 0: s.top()-i; 
			s.push(i);
		}
		return res;
    }
};
