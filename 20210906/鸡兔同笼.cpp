#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'

int main() {
	int n, a;
	int min, max;
	
	while (cin >> a) {
		
		if (a % 2 == 1 || a == 0) {
			cout << 0 << " " << 0<<endl;
			continue;
		}
		
		min = a / 4;
		if (a % 4 != 0)
			min++;
		max = a / 2;
		
		cout << min << " " << max << endl;
	}

}
