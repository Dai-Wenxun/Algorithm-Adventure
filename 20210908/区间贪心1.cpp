#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'

struct qj {
	int x;
	int y;
};

bool comp(struct qj qj1, struct qj qj2) {
	return qj1.y < qj2.y;
}

int main(void) {
	int n;
	int cnt = 0;
	int x, y;
	cin >> n;
	
	struct qj qjs[n];
	
	for (int i = 0; i < n; ++i) {
		cin >> qjs[i].x >> qjs[i].y;
	}
	
	sort(qjs, qjs+n, comp);
	
	int cur_time = 0;
	
	for (int i = 0; i < n; ++i)
		cout << qjs[i].x << " " << qjs[i].y << endl;
	
	for (int i = 0; i < n; ++i) {
		if (qjs[i].x >= cur_time) {
			cur_time = qjs[i].y;
			cnt++;
		}
	}
	
	cout << cnt << endl;
}

