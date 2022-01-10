class Solution {
public:
    int minSwaps(vector<int>& nums)
    {
        if (nums.size() <= 1) return 0;

        int onesum = 0;
        for (auto num: nums)
            if (num == 1)
                onesum += 1;
        int min = nums.size();

        int zeronum_window = 0;
        for (int i = 0; i < onesum; ++i)
            if (nums[i] == 0)
                zeronum_window += 1;
            
        for (int i = 1; i <= nums.size(); i++)
        {
            zeronum_window += (nums[(onesum + i - 1)%nums.size()] == 0); // 加入窗口右边的一个
            zeronum_window -= (nums[i - 1] == 0);                 // 除去窗口左边的一个
            min = zeronum_window < min ? zeronum_window : min;
        }
        return min;
    }
};
