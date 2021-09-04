#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

#define endl '\n'


int mo(string &str) {
	return (str[str.size() - 1] - '0') % 2; 
}

string div(string &str) {
	int shang, yu = 0;
	
	for (int i = 0; i < str.size(); ++i) {	
		shang = (str[i] - '0' + 10 * yu) / 2;
		yu = (str[i] - '0' + 10 * yu) % 2;
		
		str[i] = shang + '0'; 
	}
	
	int index = 0;
	while (str[index] == '0')
		index++;
		
	return str.substr(index);
}

int main() {
	string str;
	int yu;
	
	
	while(getline(cin, str)) {
		stack<int> s;
		
		while(str != "") {
			s.push(mo(str));
			str = div(str);	
		}
		
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
	
}
