class Solution {
public:
	vector<int> visited;
	vector<int> path;
	bool hasC = false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        
        visited.resize(numCourses);
        path.resize(numCourses);
        for (int i = 0; i < numCourses; ++i) {
        	traverse(graph, i);
		}
		return !hasC;
    }
    
    void traverse(vector<vector<int>>& graph, int s) {
		if (path[s]) {
			hasC = true;
		}
    	if (visited[s] == 1)
    		return ;
    	visited[s] = 1;
    	
    	path[s] = 1;
    	for (int i: graph[s]) {
    		traverse(graph, i);
		}
		path[s] = 0;
	}
    
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<vector<int>> graph; 
		graph.resize(numCourses);
		
		for (auto edge: prerequisites) {
			int from = edge[1];
			int to = edge[0];
			
			graph[from].push_back(to);
		}
		
		return graph;
	} 
};
