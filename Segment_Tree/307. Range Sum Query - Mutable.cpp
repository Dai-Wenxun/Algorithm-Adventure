class NumArray {
public:
    vector<int> sum, cp_nums;
    NumArray(vector<int>& nums) {
    	cp_nums = nums;
        sum.resize(4 * nums.size());
        build(0, 0, nums.size()-1);
    }


    void build(int p, int lc, int rc) {
        if (lc == rc) {
            sum[p] = cp_nums[lc];
            return;
        }

        int mid = (lc+rc)>>1;
        build(p*2+1, lc, mid);
        build(p*2+2, mid+1, rc);

        sum[p] = sum[p*2+1] + sum[p*2+2];
    }

    void change(int p, int lc, int rc, int index, int val) {
        if (lc == rc) {
            sum[p] = val;
            return;
        }

        int mid = (lc + rc) >> 1;

        if (index <= mid)
            change(2*p+1, lc, mid, index, val);
        else
            change(2*p+2, mid+1, rc, index, val);

        sum[p] = sum[p*2+1] + sum[p*2+2];
    }

    int query(int p, int lc, int rc, int ls, int rs) {
		if (lc >= ls && rc <= rs)
			return sum[p];
		
		if (ls > rc || rs < lc)
			return 0;
		
		int mid = (lc + rc) >> 1;
		
		return query(2*p+1, lc, mid, ls, rs) + query(2*p+2, mid+1, rc, ls, rs);
    }

    void update(int index, int val) {
        change(0, 0, cp_nums.size()-1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, cp_nums.size()-1, left, right);
    }
};
