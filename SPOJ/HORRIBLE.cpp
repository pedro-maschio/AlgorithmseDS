#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
const ll INF = (ll)(1e18);
const ll MOD = 1000000007;
const ll MAX = 100010;
using namespace std;

vector<ll> tree, lazy;

void propagate(ll l, ll r, ll no) {
	if(lazy[no] != 0) {
		tree[no] += (r-l+1)*lazy[no];

		if(l != r) {
			lazy[2*no] += lazy[no];
			lazy[2*no+1] += lazy[no];
		} 
		lazy[no] = 0;
	}
}

ll query(ll A, ll B, ll l, ll r, ll no) {
	propagate(l, r, no);

	if(r < A || B < l)
		return 0;
	if(l >= A && r <= B)
		return tree[no];

	ll mid = (l + r)/2;

	ll sumLeft = query(A, B, l, mid, 2*no);
	ll sumRight = query(A, B, mid+1, r, 2*no+1);

	return sumLeft + sumRight;
}

void updateInterval(ll A, ll B, ll x, ll l, ll r, ll no) {
	propagate(l, r, no);

	if(r < A || B < l) 
		return;
	if(l >= A && r <= B) {
		lazy[no] = x;

		propagate(l, r, no);
		return;
	}

	ll mid = (l + r)/2;

	updateInterval(A, B, x, l, mid, 2*no);
	updateInterval(A, B, x, mid+1, r, 2*no+1);

	tree[no] = tree[2*no] + tree[2*no+1];
}

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);


	ll n, q, t;

	cin >> t;

	while(t--) {
		cin >> n >> q;

		tree.assign(4*n, 0);
		lazy.assign(4*n, 0);

		for(ll i = 0; i < q; i++) {
			ll o, a, b, k;

			cin >> o >> a >> b;

			--a, --b;

			if(a > b)
				swap(a, b);

			if(o == 0) {
				cin >> k;

				updateInterval(a, b, k, 0, n-1, 1);
			} else {
				cout << query(a, b, 0, n-1, 1) << endl;
			}
		}
	}

    return 0;
}