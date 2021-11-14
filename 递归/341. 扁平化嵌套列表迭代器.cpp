class NestedIterator {
public:
	
	vector<int> nums;
	vector<int>::iterator begin;
    NestedIterator(vector<NestedInteger> &nestedList) {
    	for (int i = 0; i < nestedList.size(); ++i) {
    		traverse(nestedList[i]);
		}
    	
        begin = nums.begin();
    }
    
    int next() {
        return *(begin++);
    }
    
    bool hasNext() {
        return begin != nums.end();
    }
    
    void traverse(NestedInteger &Integer) {
    	if (Integer.isInteger()) {
    		nums.push_back(Integer.getInteger());
    		return ;
		} else {
			auto &list = Integer.getList();
			for (int i = 0; i < list.size(); ++i) {
				traverse(list[i]);
			} 
		}
	}  
};

class NestedIterator {
public:
	list<NestedInteger> nums;
    NestedIterator(vector<NestedInteger> &nestedList) {
    	for (int i = 0; i < nestedList.size(); ++i) {
    		nums.push_back(nestedList[i]);
		}
    }
    
    int next() {
    	int num = nums.front().getInteger();
    	nums.pop_front();
        return num;
    }
    
    bool hasNext() {
        while(!nums.empty() && !nums.front().isInteger()) {
        	auto first = nums.front().getList();
            nums.pop_front(); 

        	for (auto begin = first.rbegin(); begin != first.rend(); ++begin) {
        		nums.push_front(*begin);
			}
		}
		return !nums.empty();
    }
};

