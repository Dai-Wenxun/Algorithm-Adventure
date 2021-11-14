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
