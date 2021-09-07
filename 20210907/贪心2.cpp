#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'

bool comp(int x, int y) {
	return x > y;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		
		int a[n], b[m];
		
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
		}
		sort(a, a+n, comp);
		sort(b, b+m);
		
		int max = m > n ? m : n;
		int sum = 0;
		
		for (int i = 0; i < max; ++i) {
			sum += a[i] - b[i];
		}
		
		cout << sum << endl;
	} 
}
