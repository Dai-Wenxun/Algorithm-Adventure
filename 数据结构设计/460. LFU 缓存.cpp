class Node {
public:
	int key, val, freq;
	Node *next, *prev;
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
		auto node = it->second;
		int val = node->val; 
		int freq = node->freq;
		freq_table[freq].erase(node);
		if (freq_table[freq].size() == 0) {
			freq_table.erase(freq);
			if (minfreq == freq) minfreq += 1;
		} 
		freq_table[freq+1].emplace_front(key, val, freq+1);
		key_table[key] = freq_table[freq+1].begin();
		return val;
    }
    
    void put(int key, int value) {
    	if (capacity == 0) return ;
    	auto it = key_table.find(key);
    	
    	if (it == key_table.end()) {
    		if (key_table.size() == capacity) {
    			auto node = freq_table[minfreq].back();
    			key_table.erase(node.key);
    			freq_table[minfreq].pop_back();
    			if (freq_table[minfreq].size() == 0) {
    				freq_table.erase(minfreq);
				}
			}
			freq_table[1].emplace_front(key, value, 1);
			key_table[key] = freq_table[1].begin();
			minfreq = 1;
		} else {
			list<Node>::iterator node = it->second;
			int freq = node->freq;
			freq_table[freq].erase(node);
			if (freq_table[freq].size() == 0) {
				freq_table.erase(freq);
				if (minfreq == freq) minfreq += 1;
			} 
			freq_table[freq+1].emplace_front(key, value, freq+1);
			key_table[key] = freq_table[freq+1].begin();
		}
    }
};
