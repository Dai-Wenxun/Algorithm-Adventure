template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

class Solution {
public:
    int countElements(vector<int>& a) {
        int n = a.size();
        int mx = -1e5, mn = 1e5;
        for (int v: a) chkMax(mx, v), chkMin(mn, v);
        int c = 0;
    	for (int v: a)
    		if (v != mx && v != mn) c++;
    	return c;
    }
};
