#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

#define endl '\n'


int main() {
	int n;
    cin >> n;
    stack<long long> s;
    char c;
    long long num;

    for (int i = 0; i < n; ++i) {
        cin >> c;

        switch (c) {
            case 'A':
                if (!s.empty())
                    cout << s.top() << endl;
                else 
                    cout << "E" << endl;
                break;
            case 'P':
                cin >> num;
                s.push(num);
                break;
            case 'O':
                if (!s.empty()) 
                    s.pop();
                break;
        }
    }
    cout << endl;
	return 0;
}
