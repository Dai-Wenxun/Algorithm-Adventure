class Solution {
public:
	int m, n;
	vector<vector<char>> tmp;
    void solve(vector<vector<char>>& board) {
		m = board.size();
		n = board[0].size();
		tmp = board;
		
		for (int i = 0; i < m; ++i) {
			dfs(i, 0); dfs(i, n-1);
		}
		
		for (int j = 0; j < n; ++j) {
			dfs(0, j); dfs(m-1, j);
		}
			
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (tmp[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}

    }
    
    void dfs(int i, int j) {
    	if (i < 0 || i >= m || j < 0 || j >= n) 
    		return ;
    		
    	if (tmp[i][j] == 'O') {
    		tmp[i][j] = '$'; 
	
    		dfs(i-1, j);
    		dfs(i+1, j);
    		dfs(i, j-1);
    		dfs(i, j+1);
		}
	} 
};
