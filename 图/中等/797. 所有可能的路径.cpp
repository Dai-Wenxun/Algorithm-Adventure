class Solution {
public:
    vector<vector<int>> res;
    vector<int> onPath;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		traverse(graph, 0);
		return res;
    }
    
    void traverse(vector<vector<int>>& graph, int s) {
    	onPath.push_back(s);
    	
    	int n = graph.size();
    	
    	if (s == n - 1) {
    		res.push_back(vector<int>(onPath.begin(), onPath.end()));
    		onPath.pop_back();
    		return ;
		}
		
		for (int v: graph[s]) {
			traverse(graph, v);
		}
		
		onPath.pop_back();
	}
};
