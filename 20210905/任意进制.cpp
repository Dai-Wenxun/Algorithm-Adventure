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



#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


char inttc(int c) {
	if (0 <= c && c<= 9) {
		return c + '0'; 
	} else {
		return c + 'A' - 10;
	}
}



int ctint(char c) {
	if (isdigit(c))
		return c - '0';
	else 
		return tolower(c) - 'a' + 10;
} 


int main() {
	string str;
	int a, b;
	
	cin >> a >> str >> b;
	
	long long n1 = 0;
	
	if (str == "0") {
		cout << '0';
		return 0; 
	} 
	
	for (int i = 0; i < str.size(); ++i) {
		n1 = n1 * a + ctint(str[i]); 
	}
	
//	cout << n1;
	
	vector<int> v;
	
	while (n1 != 0) {
		v.push_back(n1 % b);
		n1 /= b;
	}	
	
	for (int i = v.size() - 1; i >= 0; --i) {
		cout << inttc(v[i]);
	}

}
