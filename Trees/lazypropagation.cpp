#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
const ll INF = (ll)(1e18);
const ll MOD = 1000000007;
const ll MAX = 1010;
using namespace std;

vector<ll> tree, lazy;
vector<int> vetor;

void build(int l, int r, int no) {
	if(l == r) {
		tree[no] = vetor[l];
		return;
	}

	int mid = (l + r) / 2;

	build(l, mid, 2*no);
	build(mid+1, r, 2*no+1);

	tree[no] = tree[2*no] + tree[2*no+1];
}


void update(int id, int v, int l, int r, int no) {
	if(l == r) {
		tree[no] = v;
		return;
	}

	int mid = (l + r) / 2;

	if(id <= mid) {
		update(id, v, l, mid, 2*no);
	} else {
		update(id, v, mid+1, r, 2*no+1);
	}

	tree[no] = tree[2*no] + tree[2*no+1];
}

void propagate(int l, int r, int no) {
	if(lazy[no] != -1) {
		tree[no] = (r-l+1)*lazy[no];

		if(l != r) {
			lazy[2*no] = lazy[no];
			lazy[2*no+1] = lazy[no];
		} 
		lazy[no] = -1;
	}
}

ll query(int A, int B, int l, int r, int no) {
	propagate(l, r, no);

	if(r < A || B < l)
		return 0;
	if(l >= A && r <= B)
		return tree[no];

	int mid = (l + r)/2;

	ll sumLeft = query(A, B, l, mid, 2*no);
	ll sumRight = query(A, B, mid+1, r, 2*no+1);

	return sumLeft + sumRight;
}

void updateInterval(int A, int B, int x, int l, int r, int no) {
	propagate(l, r, no);

	if(r < A || B < l) 
		return;
	if(l >= A && r <= B) {
		lazy[no] = x;

		propagate(l, r, no);
		return;
	}

	int mid = (l + r)/2;

	updateInterval(A, B, x, l, mid, 2*no);
	updateInterval(A, B, x, mid+1, r, 2*no+1);

	tree[no] = tree[2*no] + tree[2*no+1];
}

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);


	int n, q;

	cin >> n >> q;

	vetor.resize(n);
	tree.resize(4*n);
	lazy.assign(4*n, -1);

	for(auto &el: vetor) cin >> el;

	build(0, n-1, 1);

	for(int i = 0; i < q; i++) {
		int o, a, b, k;

		cin >> o >> a >> b;

		--a, --b;
		if(o == 1) {
			cin >> k;

			updateInterval(a, b, k, 0, n-1, 1);
		} else {
			cout << query(a, b, 0, n-1, 1) << endl;
		}
	}

    return 0;
}
 