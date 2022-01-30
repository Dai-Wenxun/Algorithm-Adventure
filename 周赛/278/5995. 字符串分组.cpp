#define fi first
class Solution {
public:
	unordered_map<int, int> fa, size;
	int groups = 0, maxSize = 0;
	
	int find(int x) {
		return fa[x] != x ? fa[x] = find(fa[x]) : x; 
	}
	
	void merge(int x, int y) {
		if (!fa.count(y)) return ;
		x = find(x);
		y = find(y);
		if (x == y) return ;
		
		fa[x] = y;
		size[y] += size[x];
		maxSize = max(maxSize, size[y]);
		--groups;
	}
	
    vector<int> groupStrings(vector<string>& words) {
        groups = words.size();
        for (auto& word: words) {
        	int x = 0;
        	for (char c: word)
        		x |= 1 << (c-'a');
        	
        	fa[x] = x;
        	++size[x];
        	maxSize = max(size[x], maxSize);
        	if (size[x] > 1)
        		--groups;
		}
		
		for (auto& p: fa) {
			for (int i = 0; i < 26; ++i) {
				merge(p.fi, p.fi ^ (1 << i));
				if ((p.fi >> i) & 1) {
					for (int j = 0; j < 26; ++j) {
						if (((p.fi >> j) & 1) == 0) {
							merge(p.fi, p.fi ^ (1 << i) | (1 << j));
						}
					}
				}
			}
		}
		return vector<int>{groups, maxSize};
    }
};
