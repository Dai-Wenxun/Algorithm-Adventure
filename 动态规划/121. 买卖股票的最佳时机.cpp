class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int sz = SZ(prices);
		int curMax =0;
		vector<int> res(sz);
		per(i, sz-1, 0) {
			curMax = max(curMax, prices[i]);
			res[i] = curMax == 0 ? 0 : curMax - prices[i];
		}
		
		return *max_element(res.begin(), res.end());
    }
};
