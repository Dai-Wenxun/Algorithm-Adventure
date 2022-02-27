class Solution {
public:
    int MOD = (int)1e9+7;
    int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int numberOfGoodSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnts(32);
        for (int i : nums) cnts[i]++;
        int mask = 1 << 10;
        vector<long long> f(mask);
        f[0] = 1;
        for (int i = 2; i <= 30; i++) {
            if (cnts[i] == 0) continue;
            int cur = 0, x = i;
            bool ok = true;
            for (int j = 0; j < 10; j++) {
                int t = p[j], c = 0;
                while (x % t == 0) {
                    cur |= (1 << j);
                    x /= t; c++;
                }
                if (c > 1) { 
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (int prev = mask - 1; prev >= 0; prev--) {
                if ((prev & cur) != 0) continue;
                f[prev | cur] = (f[prev | cur] + f[prev] * cnts[i]) % MOD;
            }
        }
        int ans = 0;
        for (int i = 1; i < mask; i++) ans = (ans + f[i]) % MOD;
        for (int i = 0; i < cnts[1]; i++) ans = ans * 2 % MOD;
        return ans;
    }
};
