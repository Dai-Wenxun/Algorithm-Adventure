class FreqStack {
public:
	unordered_map<int, stack<int>> fv;
	unordered_map<int, int> vf;  
	int maxfreq = 0;
    FreqStack() {}
    
    void push(int val) {
		int& freq = vf[val];
		freq++;
		fv[freq].push(val);
		maxfreq = max(freq, maxfreq); 
    }
    
    int pop() {
    	auto& sk = fv[maxfreq];
		int res = sk.top();
		sk.pop();
		if (sk.empty()) {
			fv.erase(maxfreq);
			--maxfreq;
		}
		int& freq = vf[res];
		freq--;
		if (!freq) 
			vf.erase(res);
		return res;
    }
};
