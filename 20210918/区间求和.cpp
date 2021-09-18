#include <bits/stdc++.h> 
#define ll long long
#define endl '\n'
using namespace std;

constexpr int maxn = 1e5;
constexpr int MO = 571373;

struct Node {
	int l, r;
	ll val, add, mu;
} res[4*maxn];

int a[maxn];


void push_down(int p) {
	int ln = 2*p+1, rn = 2*p+2;
	
	res[ln].val = (res[p].add * (res[ln].r-res[ln].l+1) + res[p].mu * res[ln].val % MO) % MO;
	res[rn].val = (res[p].add * (res[rn].r-res[rn].l+1) + res[p].mu * res[rn].val % MO) % MO;
	
	res[ln].add = (res[ln].add * res[p].mu % MO + res[p].add) % MO;
	res[rn].add = (res[rn].add * res[p].mu % MO + res[p].add) % MO;
	
	res[ln].mu = res[ln].mu * res[p].mu % MO;
	res[rn].mu = res[rn].mu * res[p].mu % MO;
	
	res[p].add = 0;
	res[p].mu = 1;
 }

void build(int p, int l, int r) {
	res[p].l = l;
	res[p].r = r;
	res[p].mu = 1;
	
	if (l == r) {
		res[p].val = a[l];
		return;
	}
	
	int mid = (l + r)>>1;
	
	build(2*p+1, l, mid);
	build(2*p+2, mid+1, r);
	res[p].val = res[2*p+1].val + res[2*p+2].val;
}

void add(int p, int l, int r, int k) {
	if (res[p].l >= l && res[p].r <= r) {
		res[p].add += k;
		(res[p].val += (res[p].r-res[p].l+1) * k) %= MO;
		return;
	}
	push_down(p);
	int mid = (res[p].l + res[p].r) >> 1;
	if (l <= mid)
		add(2*p+1, l, r, k);
	if (r >= mid+1)
		add(2*p+2, l, r, k);
	
	res[p].val = (res[2*p+1].val + res[2*p+2].val)%MO;
}

void mul(int p, int l, int r, int k) {
	if (res[p].l >= l && res[p].r <= r) {
		res[p].add *= k;
		res[p].mu *= k;
		res[p].val = (res[p].val * k);
		return;
	}
	push_down(p);
	int mid = (res[p].l + res[p].r) >> 1;
	if (l <= mid)
		mul(2*p+1, l, r, k);
	if (r >= mid+1)
		mul(2*p+2, l, r, k);
	
	res[p].val = (res[2*p+1].val + res[2*p+2].val); 
}

ll query(int p, int l, int r) {
	if (res[p].l >= l && res[p].r <= r) {
		return res[p].val;
	}
	push_down(p);
	ll ans = 0;
	int mid = (res[p].l+res[p].r) >> 1;
	if (l <= mid)
		ans += query(2*p+1, l, r);
	if (r >= mid+1)
		ans += query(2*p+2, l, r);
	
	return ans; 
}

int main() {
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	build(0, 0, n-1);
	
	int op, l, r;
	for (int i = 0; i < m; ++i) {
		cin >> op;
		switch(op) {
			case 1:
				int k;
				cin >> l >> r >> k;
				mul(0, l-1, r-1, k);
				break;
			case 2:
				cin >> l >> r >> k;
				add(0, l-1, r-1, k);
				break;	
			case 3:
				cin >> l >> r;
				cout << query(0, l-1, r-1)%p << endl;
				break; 
		}
	}
}
