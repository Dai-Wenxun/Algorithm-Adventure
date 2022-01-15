class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<vector<int>> dp(n, vector<int>(n));
		
		for (int i = 0; i < n; ++i)
			dp[0][i] = matrix[0][i];
		
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < n; ++j) {			
				int min_sum = dp[i-1][j];
				if (j > 0)
					min_sum = min(min_sum, dp[i-1][j-1]);
				if (j < n-1)
					min_sum = min(min_sum, dp[i-1][j+1]);
				
				dp[i][j] = min_sum + matrix[i][j];
			}
		}

//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; ++j) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }

		int sum = INT_MAX;
		for (int i = 0; i < n; ++i) 
			sum = min(dp[n-1][i], sum); 
		
		return sum;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<int> dp(matrix[0].begin(), matrix[0].end());
		
		for (int i = 1; i < n; ++i) {
			int pre = 0;
			for (int j = 0; j < n; ++j) {
				int tmp = dp[j];
				
				int min_sum = dp[j];
				if (j > 0)
					min_sum = min(min_sum, pre);
				if (j < n-1)
					min_sum = min(min_sum, dp[j+1]);
				
				dp[j] = min_sum + matrix[i][j];
				
				pre = tmp;
			}
		}
		int sum = INT_MAX;
		for (int i = 0; i < n; ++i) 
			sum = min(dp[i], sum); 
		
		return sum;
    }
};
