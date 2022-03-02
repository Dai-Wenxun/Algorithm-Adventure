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

# 双指针：



# 滑动窗口：

### 3. 无重复字符的最长子串

![](./images/3.png)

思路：利用桶记录冲突字符index，避免遍历查找

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int sz = SZ(s);
		if (!sz) return 0;
		vector<int> mp(128, -1);
		int mx = INT_MIN;
		int i = 0, j = 0;
		while (j < sz) {
			int idx = mp[s[j]];	
			if (idx >= i) {
				i = idx + 1;
			}
			mp[s[j]] = j;
			mx = max(mx, j - i + 1);
			++j;
		}
		return mx;
    }
};
```

# 二分：

### 4. 寻找两个正序数组的中位数