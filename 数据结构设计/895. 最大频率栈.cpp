class FreqStack {
public:
	unordered_map<int, stack<int>> fv;
	unordered_map<int, int> vf;  
	int maxfreq = 0;
    FreqStack() {
		fv.clear();
		vf.clear();
	}
    
    void push(int val) {
		auto it = vf.find(val);
		if (it == vf.end()) {
			vf[val] = 1;
			fv[1].push(val);
			if (maxfreq == 0)
				maxfreq = 1;
		} else {
			vf[val] += 1;
			fv[vf[val]].push(val);
			if (maxfreq < vf[val])
				maxfreq = vf[val];
		}
    }
    
    int pop() {
		int res = fv[maxfreq].top();
		fv[maxfreq].pop();
		vf[res]--;
		if (fv[maxfreq].empty()) {
			fv.erase(maxfreq);
			maxfreq--;
		}
		if (vf[res] == 0) {
			vf.erase(res);
		}
		return res;
    }
};
