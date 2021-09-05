#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

#define endl '\n'

int CharToInt(char c) {
	if (isdigit(c)) {
		return c - '0';
	} else {
		return tolower(c) - 'a' + 10;
	}
}

int main() {
	string str;
	int M, N;
	cin >> M >> N >> str;
	
	long long num = 0;

	for (int i = 0; i < str.size(); ++i) {
		num = num * M + CharToInt(str[i]);
	}
	
//	cout << num << endl;
	
	vector<int> v;
	while (num != 0) {
		v.push_back(num % N);
		num = num / N; 
	}
	
	for (int i = v.size() - 1; i >= 0; --i) {
		cout << v[i];
	}
	 
}
