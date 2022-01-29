typedef pair<int, int> pii;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<vector<pii>> g(n);
		queue<pii> q;
		for (auto& x: flights)
			g[x[0]].emplace_back(x[1], x[2]);
		
		vector<int> ans(n, INT_MAX);
		q.emplace(src, 0);	
		while (k >= 0 && !q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; ++i) {
				auto s = q.front(); q.pop(); 
				for (auto& node: g[s.first]) {
					int nextP = s.second+node.second;
					if (nextP < ans[node.first]) {
						ans[node.first] = nextP; 
						q.emplace(node.first, nextP);
					}	
				}
			}
			k--;
		}
		return ans[dst] == INT_MAX ? -1 : ans[dst];
    }
};
