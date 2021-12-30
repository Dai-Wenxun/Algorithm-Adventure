class State {
public:
	int id;
	int dist;
	State(int id, int dist): id(id), dist(dist) {}
	
	bool operator< (const State& other) const {
		return this->dist > other.dist;
	}
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
		for (vector<int>& e: times) 
			g[e[0]-1].emplace_back(e[1]-1, e[2]);
		
		vector<int> res = dijkstra(k-1, g);
		int max_time = *max_element(res.begin(), res.end());
		return max_time == INT_MAX ? -1 : max_time; 
    }
    
    vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& g) {
    	vector<int> dists(g.size(), INT_MAX);
    	dists[start] = 0;
    	
    	priority_queue<State> pq;
    	
    	pq.emplace(start, 0);
    	
    	while (!pq.empty()) {
    		State curS = pq.top(); pq.pop();
    		int curID = curS.id;
    		int curDist = curS.dist;
    		
    		if (curDist > dists[curID]) 
    			continue;
    		
    		for (auto next: g[curID]) {
    			int nextID = next.first;
    			int nextDist = dists[curID] + next.second;
    			if (nextDist < dists[nextID]) {
    				dists[nextID] = nextDist;
    				pq.emplace(nextID, nextDist);
				}
			}
		}
    	return dists;
	}
};
