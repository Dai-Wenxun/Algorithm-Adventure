class Solution {
public:
	vector<int> mp = vector<int>(31);
    int fib(int n) {
    	if (n == 0) return 0;
		if (n == 1) return 1;
		if (mp[n])
			return mp[n];
		
		int res = fib(n-1) + fib(n-2); 
    	mp[n] = res;
    	return res;
	}
};

class Solution {
public:
    int fib(int n) {
    	if (n == 0) return 0;
		if (n == 1) return 1;
		
		int dp[n+1];
		
		dp[0] = 0;
		dp[1] = 1;
				
		for (int i = 2; i <= n; ++i) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		
		return dp[n];
    }
};

class Solution {
public:
    int fib(int n) {
    	if (n == 0) return 0;
		if (n == 1) return 1;
		
		int cur = 1, prev = 0;
				
		for (int i = 2; i <= n; ++i) {
			int sum = cur + prev;
			prev = cur;
			cur = sum;
		}
		
		return cur;
    }
};
