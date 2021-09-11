#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Station {
    double money;
    int dist;
    int index;

    bool operator() (Station& s1, Station& s2) {
        return s1.money < s2.money;
    }
};



int main() {
    int max_tank, d, avg, n;
	
    while (cin >> max_tank >> d >> avg >> n) {
        Station stations[n];
		int flag[30001];
		memset(flag, 0, 30001 * sizeof(int));
		
        for (int i = 0; i < n; ++i)
            cin >> stations[i].money >> stations[i].dist;

        sort(stations, stations+n, Station());
		
//		cout << endl;
//		for (int i = 0; i < n; ++i)
//            cout << stations[i].money << " " << stations[i].dist << endl;
		
		const int max_dist = max_tank * avg;
		double sum = 0;
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			for (int j = stations[i].dist; j < d && j < stations[i].dist + max_dist; ++j) {
				if (flag[j] != 1) {
					flag[j] = 1;
					cnt++;
				}
			}
			sum += cnt * 1.0 / avg * stations[i].money;
		}
		
		int i;
		for (i = 0; i < d; ++i) {
			if (flag[i] == 0) {
				printf("The maximum travel distance = %.2f\n", (float)i);
				break;
			}
		}
		if (i == d)
			printf("%.2f\n", sum);
    }
}
