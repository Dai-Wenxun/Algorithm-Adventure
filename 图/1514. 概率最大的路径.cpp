typedef pair<double, int> pii; 

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		vector<vector<pii>> g(n);
		for (int i = 0; i < edges.size(); ++i) {
			int x = edges[i][0];
			int y = edges[i][1];
			g[x].emplace_back(succProb[i], y);
			g[y].emplace_back(succProb[i], x);	
		}
		
		vector<double> dists(n);
		dists[start] = 1; 
		priority_queue<pii> pq;
		pq.emplace(1, start);
		
		while (!pq.empty()) {
			pii curP = pq.top(); pq.pop();
			double cur_dist = curP.first;
			int cur_id = curP.second;
			
			if (cur_id == end)
				return cur_dist;
			
			if (cur_dist < dists[cur_id])
				continue;
				 
			for (auto& nextP: g[cur_id]) {
				double next_dist = nextP.first * dists[cur_id];
				int next_id = nextP.second;
				
				if (next_dist > dists[next_id]) {
					dists[next_id] = next_dist;
					pq.emplace(next_dist, next_id);
				}
			}
		}
		return 0;
    }
};
