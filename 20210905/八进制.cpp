#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int cti(char c) {
	if (isdigit(c)) {
		return c - '0';
	} else {
		return tolower(c) - 'a' + 10;
	}
}

char itc(int c) {
	return c + '0';
}



string Divide(string str, int radix) {
	int cur = 0;
	
	for (int i = 0; i < str.size(); ++i) {
		cur = cur * 10 + cti(str[i]);
		str[i] = itc(cur / radix);
		cur = cur % radix;
	}
	
	int index = 0;
	while (str[index] == '0') 
		index++;
	
	return str.substr(index);
}






int main() {
	string str;
	while(cin >> str) {
		vector<int> v;
	
		while (str.size() != 0) {
			v.push_back(cti(str[str.size() - 1]) % 2);
			str = Divide(str, 2);
		}
		
		int size = v.size();
		if (size % 3 != 0)
			for (int i = 0; i < (3-(size % 3)); ++i)
				v.push_back(0);
		
		for (int i = 0; i < v.size(); i+=3) {
			str += itc(v[i] + v[i+1] * 2 + v[i+2] * 4);
		}
		for (int i = str.size() - 1; i >= 0; --i)
			cout << str[i];
		cout << endl;
	} 

}
