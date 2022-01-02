#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int key, val;
	Node *next, *prev;
	Node (int k, int v): key(k), val(v) {} 
};

class LRUCache {
public:
	unordered_map<int, Node*> map;
	int capacity;
	int size;
	Node *head, *tail;
    LRUCache(int _capacity): capacity(_capacity), size(0) {
		head = new Node(0, 0);
		tail = new Node(0, 0);
		head->next = tail;
		tail->prev = head;
    }
    
    int get(int key) {
		if (!map.count(key))
			return -1;
		Node *node = map[key];
		removeNode(node);
		addToHead(node);
		return node->val; 
    }
    
    void put(int key, int value) {
		if (!map.count(key)) {
			Node *node = new Node(key, value);
			map[key] = node;
			addToHead(node);
		} else {
			Node *node = map[key];
			removeNode(node);
			node->val = value;
			addToHead(node);
		}
    }
    
    void removeNode(Node *node) {
		node->next->prev = node->prev;
		node->prev->next = node->next;
		size--;
	}
    
    void addToHead(Node *node) {
    	node->next = head->next;
    	node->next->prev = node;
    	head->next = node;
    	node->prev = head;
    	size++; 
    	
    	if (size > capacity) {
    		map.erase(tail->prev->key);
    		removeNode(tail->prev);
		}
	}
};

int main() {
	LRUCache lru(2);
	lru.put(2, 1);
	lru.put(2, 2);
	cout << lru.get(2) << endl;
	lru.put(1, 1);
	lru.put(4, 1);
	cout << lru.get(2) << endl;
}

