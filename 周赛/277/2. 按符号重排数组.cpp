#define pb push_back
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        vector<int> x, y;
        for (int v: a)
        	if (v > 0) x.pb(v);
        	else y.pb(v);
        vector<int> c;
        for (int i = 0; i < x.size(); i++)
        	c.pb(x[i]), c.pb(y[i]);
       	return c;
    }
};
