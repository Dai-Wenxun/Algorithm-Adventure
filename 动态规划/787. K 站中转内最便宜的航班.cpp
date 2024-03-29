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

typedef pair<int, int> pii;

class Solution {
public:
	static constexpr int INF = 1000007;
	
	vector<vector<int>> memo;
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
		vector<vector<pii>> g(n);
		memo = vector<vector<int>>(n, vector<int>(k+2));
		dfs(g, k+1, src, dst);
		
		return memo[src][k+1] >= INF ? -1 : memo[src][k+1];
    }
    
    int dfs(vector<vector<int>>& f, int k, int cur, int dst) {
		if (k < 0)
			return INF;
    	
    	if (memo[cur][k])
    		return memo[cur][k];
    	
    	if (cur == dst)
			return 0;
		
		int res = INF;
    	for (auto& p: f) {
    		if (p[0] == cur) 
    			res = min(dfs(f, k-1, p[1], dst)+p[2], res);
		}
		
		memo[cur][k] = res; 
		return res;
	}
};

class Solution {
public:
	
	static constexpr int INF = 1000007;
	
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<vector<int>> dp(n, vector<int>(k+2, INF));
		dp[dst][0] = 0;
		for (int i = 1; i <= k+1; ++i) {
			for (auto& f: flights) {
				dp[f[0]][i] = min(dp[f[1]][i-1] + f[2], dp[f[0]][i]);
			}	
		}
		int res = *min_element(dp[src].begin(), dp[src].end());
		return res == INF ? -1 : res;
    }
};

class Solution {
public:
	static constexpr int INF = 1000007;
	
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<vector<int>> dp(n, vector<int>(2, INF));
		dp[dst][0] = 0;
		int res = INF;
		for (int i = 1; i <= k+1; ++i) {
			for (auto& f: flights) {
				dp[f[0]][k&1] = min(dp[f[1]][(k-1)&1] + f[2], dp[f[0]][k&1]);
			}	
			res = min(res, dp[src][k&1]);
		}
		return res == INF ? -1 : res;
    }
};
