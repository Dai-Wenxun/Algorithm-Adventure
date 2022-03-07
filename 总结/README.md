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

### 15. 三数之和

![](./images/15.png)

思路：先排序，使用三个指针 `i`、`j` 和 `k` 分别代表要找的三个数，初始时令`j=i+1`，`k=n-1`，`sum=nums[i]+nums[j]+nums[k]`，固定`i`，移动`j`、`k`使得`sum=0`。

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		int sz = SZ(nums);
		rep(i, 0, sz-1) {
			while (i > 0 && i < sz && nums[i] == nums[i-1]) ++i;
			int j = i + 1, k = sz - 1;
			while (j < k) {
				while (j > i + 1 && j < k && nums[j] == nums[j-1]) ++j;
				if (j >= k) break;
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == 0) {
					res.pb({nums[i], nums[j], nums[k]});
					++j;
				} else if (sum < 0) {
					++j;
				} else {
					--k;
				}
			}
		} 
		return res;
    }
};
```

# 滑动窗口：

### 3. 无重复字符的最长子串

![](./images/3.png)

思路：利用桶记录冲突字符`index`，避免遍历查找。

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

![](./images/4.png)

思路：利用二分寻找第`K`小的数，始终保持递归函数中`nums1`数组长度最长以避免不必要的边界情况讨论。

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = SZ(nums1), n = SZ(nums2);
		if ((m + n) & 1)
			return searchK(nums1, 0, nums2, 0, (m + n + 1) >> 1);
		else {
			int l = searchK(nums1, 0, nums2, 0, (m + n + 1) >> 1);
			int r = searchK(nums1, 0, nums2, 0, (m + n + 2) >> 1);
			return (l + r) / 2.0;
		}
		return -1;
    }
    
    int searchK(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
    	int len1 = SZ(nums1) - s1;
    	int len2 = SZ(nums2) - s2;
    	
    	if (len1 < len2) return searchK(nums2, s2, nums1, s1, k);
		if (len2 == 0) return nums1[s1 + k - 1];
		if (k == 1) return min(nums2[s2], nums1[s1]);
    	
    	int i = s1 + min(len1, k >> 1) - 1;
    	int j = s2 + min(len2, k >> 1) - 1;
    	if (nums1[i] > nums2[j]) {
    		return searchK(nums1, s1, nums2, j+1, k - (j - s2 + 1));
		} else {
			return searchK(nums1, i+1, nums2, s2, k - (i - s1 + 1));
		}
	}
};
```

# 贪心：

### 11. 盛最多水的容器

![](./images/11.png)

思路：双指针+贪心，$S(i,j)=min(h[i], h[j])\times(j-i)$

```c++
class Solution {
public:
    int maxArea(vector<int>& h) {
		int sz = SZ(h);
		int mx = INT_MIN;
		int i = 0, j = sz - 1;
		while (i < j) {
			mx = max(mx, (i - j) * min(h[i], h[j]));
			if (h[i] < h[j]) i++;
			else j--;
		}
		return mx;
    }
};
```

