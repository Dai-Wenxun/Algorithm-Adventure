class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
		int m = SZ(matrix), n = SZ(matrix[0]); 
		
		vector<int> res;
		rep(i, 0, m-1) {
			rep(j, 0, n-1) {
				// ÐÐ 
				bool flag = true;
				rep(k, 0, n - 1) {
					if (k != j && matrix[i][k] < matrix[i][j]) {flag = false; break;}
				}
				if (!flag) continue; 
				// ÁÐ 
				rep(k, 0, m - 1) {
					if (k != i && matrix[k][j] > matrix[i][j]) {flag = false; break;}
				}
				if (!flag) continue;
				
				res.pb(matrix[i][j]);
			}
		} 
		return res;
    }
};

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
		int m = SZ(matrix), n = SZ(matrix[0]); 
		vector<int> rows(m, 2e9), cols(n, -2e9), res;	
		rep(i, 0, m-1) {
			rep(j, 0, n-1) {
				rows[i] = min(rows[i], matrix[i][j]);
				cols[j] = max(cols[j], matrix[i][j]);
			}
		}	
		rep(i, 0, m-1)
			rep(j, 0, n-1) 
				if (matrix[i][j] == rows[i] && matrix[i][j] == cols[j])
					res.pb(matrix[i][j]);
		return res;
    }
};
