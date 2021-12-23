class Solution {
public:
	vector<int> vtd;
	vector<int> color;
 	bool res = true;
    bool isBipartite(vector<vector<int>>& graph) {
    	vtd.resize(graph.size(), 0);
    	color.resize(graph.size(), 0);
		for (int i = 0; i < graph.size(); ++i) {
			if (!vtd[i]) 
				traverse(graph, i);
		}
		return res;
    }
    
    void traverse(vector<vector<int>>& graph, int cur) {
    	if (!res) return;

    	queue<int> q;
    	q.push(cur);
    	vtd[cur] = 1;
    	
    	while (!q.empty()) {
    		cur = q.front();
    		q.pop();
    		for (int v: graph[cur]) {
    			if (!vtd[v]) {
					vtd[cur] = 1;
					color[v] = !color[cur];
					q.push(v);
				} else {
					if (color[v] == color[cur]) {
    					res = false;
    					return ;
					}
				}
			}
		}
    	
    	
//    	vtd[cur] = 1;
//    	
//    	for (int v: graph[cur]) {
//    		if (!vtd[v]) {
//    			color[v] = !color[cur];
//    			traverse(graph, v);
//			} else {
//				if (color[cur] == color[v]) {
//					res = false;
//					return ;
//				}	
//			} 
//		}
	} 
};
