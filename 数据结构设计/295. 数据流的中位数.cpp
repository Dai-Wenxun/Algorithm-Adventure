class MedianFinder {
public:
	priority_queue<int, vector<int>, less<int>> low;  //大根堆 
	priority_queue<int, vector<int>, greater<int>> high; //小根堆 
    MedianFinder() {}
    		
    void addNum(int num) {
    	if (low.size() == high.size()) {
			if (low.empty() || low.top() >= num) {
				low.push(num);
			} else if (low.top() < num) {
    			high.push(num);
    			low.push(high.top());
    			high.pop();
			}  
		} else (low.size() > high.size()) {
    		if (high.empty() || high.top() <= num) {
    			high.push(num);
			} else if (high.top() > num) {
    			low.push(num);
    			high.push(low.top());
    			low.pop();
			}
		}
    }
    
    double findMedian() {
		if (low.size() == high.size()) {
			return (low.top() + high.top()) / 2.0;
		} else {
			return low.top(); 
		}
    }
};
