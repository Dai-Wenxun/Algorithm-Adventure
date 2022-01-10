typedef pair<int, int> pii;

class Solution {
public:
	int d[5] = {-1, 0, 1, 0, -1};
	int m;
	int n;
    int minimumEffortPath(vector<vector<int>>& heights) {
		m = heights.size();
		n = heights[0].size();
		
		int res = dijkstra(heights);
		return res;
    }
    int dijkstra(vector<vector<int>>& heights) {
    	int size = m * n;
    	vector<int> dists(size, INT_MAX);
    	dists[0] = 0;
    	priority_queue<pii, vector<pii>, greater<pii>> pq;
    	pq.emplace(0, 0);
    	while (!pq.empty()) {
    		pii curS = pq.top(); pq.pop();
    		int cur_x = curS.second / n;
    		int cur_y = curS.second % n;
			int cur_dist = curS.first;
			
    		if (cur_x == m-1 && cur_y == n-1)
    			return cur_dist;
    		
    		if (cur_dist > dists[cur_x * n + cur_y])
    			continue;

			for (int i = 0; i < 4; ++i) {
    			int next_x = cur_x + d[i];
    			int next_y = cur_y + d[i+1];
				if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
					continue;
				int next_dist = max(abs(heights[next_x][next_y]-heights[cur_x][cur_y]), dists[cur_x * n + cur_y]);
				if (next_dist < dists[next_x * n + next_y]) {
					dists[next_x * n + next_y] = next_dist;
					pq.emplace(next_dist, next_x * n + next_y);
				} 
			}
		}
		return INT_MAX; 
	}
};
