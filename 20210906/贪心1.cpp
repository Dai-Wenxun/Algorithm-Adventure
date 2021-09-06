#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'

const int MAXN = 1000;

struct JavaBean {
	double weight;
	double cost;
};

JavaBean arr[MAXN];

bool comp(JavaBean x, JavaBean y) {
	return (x.weight / x.cost) > (y.weight / y.cost);
}

int main() {
	double m;
	int n;
	
	
	while (cin >> m >> n) {
		if (m == -1 && n == -1)
			break;
		
		for (int i = 0; i < n; ++i)
			cin >> arr[i].weight >> arr[i].cost;
			
		sort(arr, arr + n, comp);
		
//		for (int i = 0; i < n; ++i) 
//			cout <<  arr[i].weight << arr[i].cost << endl;

		double answer = 0;
		
		for (int i = 0; i < n; ++i) {
			if (arr[i].cost < m) {
				m -= arr[i].cost;
				answer += arr[i].weight;
			} else {
				answer += (m / arr[i].cost) * arr[i].weight; 
				break;
			}
		}
		printf("%.3f\n", answer);
	}

}
