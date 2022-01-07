class Node {
public:
	int id;
	int time;
	Node(int _id, int _time): id(_id), time(_time) {}
};

class Comp {
public:
	bool operator() (Node *n1, Node *n2) {
		return n1->time < n2->time;
	}
};

class Twitter {
public:
	int time = 0;
	unordered_map<int, vector<Node*>> um;
	unordered_map<int, vector<int>> uf;
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
		um[userId].emplace_back(new Node(tweetId, time++));
    }
    
    vector<int> getNewsFeed(int userId) {
		auto it = uf.find(userId);
		vector<int> res;
		if (it == uf.end()) {
			auto& ns = um[userId];
			for (int i = ns.size()-1; i >= 0 ; --i) {
				if (res.size() == 10)
					break;
				res.push_back(ns[i]->id);
			}
		} else {
			priority_queue<Node*, vector<Node*>, Comp> pq;
			for (auto n: um[userId])
				pq.push(n);
			for (auto fid: it->second) 
				for (auto n: um[fid])
					pq.push(n);
			
			for (int i = 0; i < 10; ++i) {
				if (pq.empty())
					break;
				res.push_back(pq.top()->id); 
				pq.pop();
			}
		}
		return res; 
    }
    
    void follow(int followerId, int followeeId) {
    	auto& fs = uf[followerId];
    	auto it = find(fs.begin(), fs.end(), followeeId);
    	if (it == fs.end())
    		fs.push_back(followeeId);
		if (!fs.size())
			uf.erase(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
    	auto& fs = uf[followerId];
    	auto it = find(fs.begin(), fs.end(), followeeId);
    	if (it != fs.end())
    		fs.erase(it);
		if (!fs.size())
			uf.erase(followerId);
    }
};
