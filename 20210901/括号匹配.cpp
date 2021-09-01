#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
 

int main() {
	string str;
	while (cin >> str) {
		stack<int> brackets;
		string answer(str.size(), ' ');
		
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '(') {
				brackets.push(i);
			} else if (str[i] == ')') {
				if (!brackets.empty()) {
					brackets.pop();
				} else {
					answer[i] = '?';
				}
			}
		}
		
		while(!brackets.empty()) {
			answer[brackets.top()] = '$';
			brackets.pop();
		}
		
		cout << answer << endl;
	}
	
	
}
