class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = accumulate(nums.begin(), nums.end(), 0);
        if (cnt == nums.size() || cnt == 0 || cnt == 1) return 0;

        int j = 0;
        int window = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (true) {
                int x = (i > j) ? nums.size() + j : j;
                if (x >= i + cnt) break;
                window += nums[j];
                j = (j + 1 == nums.size()) ? 0 : j + 1;
            }
            ans = min(ans, cnt - window);
            window -= nums[i];
        }
        return ans;
    }
};
