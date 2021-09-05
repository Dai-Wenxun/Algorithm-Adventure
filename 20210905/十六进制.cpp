#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int ctint(char c) {
	if (isdigit(c))
		return c - '0';
	else 
		return c - 'A' + 10;
} 


int main() {
	string str;
	

	while (cin >> str) {
		long long res = 0;
		
		
		for (int i = 2; i < str.size(); ++i) {
			res = (res << 4) + ctint(str[i]); 
		}
		cout << res <<endl;
	}
	
}
