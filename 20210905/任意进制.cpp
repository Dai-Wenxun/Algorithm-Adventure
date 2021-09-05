#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int main() {
	int m;
	long long A, B;

	while (cin >> m && m != 0) {
		vector<int> v;
		
		cin >> A >> B;
		A = A + B;
		
		while(A != 0) {
			v.push_back(A % m);
			A /= m;
		}
		if (v.size() == 0)
			v.push_back(0);
		
		for (int i = v.size() - 1; i >= 0; --i)
			cout << v[i];
		cout << endl;
	}
}
