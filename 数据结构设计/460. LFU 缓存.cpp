class Node {
public:
	int key, val, freq;
	Node (int k, int v, int f): key(k), val(v), freq(f) {} 
};

class LFUCache {
public:
	int minfreq, capacity;
	unordered_map<int, list<Node>::iterator> key_table;
	unordered_map<int, list<Node>> freq_table;
    LFUCache(int _capacity) {
		minfreq = 0;
		capacity = _capacity;
		key_table.clear();
		freq_table.clear();
    }
    
    int get(int key) {
    	if (capacity == 0) return -1;
		auto it = key_table.find(key);
		if (it == key_table.end()) return -1;
		auto& node = it->second;
		int val = node->val; 
		int freq = node->freq;
		auto& nl = freq_table[freq];
		nl.erase(node);
		if (nl.size() == 0) {
			freq_table.erase(freq);
			if (minfreq == freq) minfreq += 1;
		} 
		nl = freq_table[freq+1];
		nl.emplace_front(key, val, freq+1);
		key_table[key] = nl.begin();
		return val;
    }
    
    void put(int key, int value) {
    	if (capacity == 0) return ;
    	auto it = key_table.find(key);
    	
    	if (it == key_table.end()) {
    		if (key_table.size() == capacity) {
    			auto& nl = freq_table[minfreq];
    			auto& n = nl.back();
    			key_table.erase(n.key);
    			nl.pop_back();
    			if (nl.size() == 0) {
    				freq_table.erase(minfreq);
				}
			}
			auto& nl = freq_table[1];
			nl.emplace_front(key, value, 1);
			key_table[key] = nl.begin();
			minfreq = 1;
		} else {
			auto& node = it->second;
			int freq = node->freq;
			auto& nl = freq_table[freq];
			nl.erase(node);
			if (nl.size() == 0) {
				freq_table.erase(freq);
				if (minfreq == freq) minfreq += 1;
			} 
			nl = freq_table[freq+1];
			nl.emplace_front(key, value, freq+1);
			key_table[key] = nl.begin();
		}
    }
};
