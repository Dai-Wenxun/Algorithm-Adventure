[TOC]

# 模拟：

### 1. 两数之和

![](./images/1.png)

思路：哈希表去重。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
		unordered_map<int, int> mp;
		int sz = SZ(nums);
		rep(i, 0, sz-1) {
			int b = t - nums[i];
			auto it = mp.find(b);
			if (it != mp.end()) return {it->se, i};
			mp[nums[i]] = i;
		}
		return {};
    }
};
```

# 双指针



# 滑动窗口

