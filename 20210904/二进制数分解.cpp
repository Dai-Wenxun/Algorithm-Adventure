#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

#define endl '\n'


int main() {
	int num;
	
	while(cin >> num) {
		stack<char> s;
		
		while (num != 0) {
			s.push(num % 2);
	//		cout << num % 2<< " " << num <<endl;
			num = num >> 1;
		} 
		
		while(!s.empty()) {
			printf("%d", s.top());
			s.pop();
		}
		cout << endl;
	}
	
}
