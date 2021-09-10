#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


const int MAXN = 200001;

struct Island {
    long long left;
    long long right;
};

struct Bridge {
    long long length;
    long long index;
};

struct Interval {
    long long minimum;
    long long maxmum;
    long long index;
    bool operator< (Interval x) const {
        return maxmum > x.maxmum;
    }
};

bool IntervalCompare(Interval x, Interval y) {
    if (x.minimum == y.minimum) {
        return x.maxmum < y.maxmum;
    } else {
        return x.minimum < y.minimum;
    }
}

bool BridgeCompare(Bridge x, Bridge y) {
    return x.length < y.length;
}


Island island[MAXN];
Bridge bridge[MAXN];
Interval interval[MAXN];
long long answer[MAXN];

bool Solve(int n, int m) {
    priority_queue<Interval> myQueue;
    int position = 0;
    int number = 0;

    for (int i = 0; i < m; ++i) {
        while(!myQueue.empty() &&
                myQueue.top().maxmum < bridge[i].length) {
            myQueue.pop();
        }

        while (position < n - 1 &&
               interval[position].minimum <= bridge[i].length &&
               interval[position].maxmum >= bridge[i].length ){
            myQueue.push(interval[position]);
            position++;
        }

        if (!myQueue.empty()) {
            Interval current = myQueue.top();
            myQueue.pop();
            answer[current.index] = bridge[i].index;
            number++;
        }
    }

    return number == n - 1;
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        memset(island, 0, sizeof(island));
        memset(bridge, 0, sizeof(bridge));
        memset(interval, 0, sizeof(interval));
        memset(answer, 0, sizeof(answer));

        for (int i = 0; i < n; ++i) {
            cin >> island[i].left >> island[i].right;
        }

        for (int i = 0; i < m; ++i) {
            cin >> bridge[i].length;
            bridge[i].index = i + 1;
        }

        for (int i = 0; i < n - 1; ++i) {
            interval[i].minimum = island[i + 1].left - island[i].right;
            interval[i].maxmum = island[i + 1].right - island[i].left;
            interval[i].index = i;
        }

        sort(interval, interval + n - 1, IntervalCompare);
        sort(bridge, bridge + m, BridgeCompare);

        if (Solve(n, m)) {
            cout << "Yes" << endl;
            for (int i = 0; i < n - 1; ++i) {
                cout << answer[i] << " ";
            }
        } else {
            cout << "No" << endl;
        }
    }
}



