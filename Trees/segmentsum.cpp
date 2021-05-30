#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
const ll INF = (ll)(1e18);
const ll MOD = 1000000007;
const ll MAX = 1010;
using namespace std;

vector<ll> tree;
vector<int> vetor;



void build(int l, int r, int no) {
	if(l == r) {
		tree[no] = vetor[l];
		return;
	}

	int mid = (l + r) / 2;

	build(l, mid, 2 * no);
	build(mid + 1, r, 2 * no + 1);

	tree[no] = tree[2*no] + tree[2*no+1];
}


ll query(int A, int B, int l, int r, int no) {
	if(r < A || B < l)
		return 0;
	if(l >= A && r <= B)
		return tree[no];

	int mid = (l + r)/2;

	ll sumLeft = query(A, B, l, mid, 2*no);
	ll sumRight = query(A, B, mid+1, r, 2*no+1);

	return sumLeft + sumRight;
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

	tree[no] = tree[2*no] +tree[2*no+1];
}

int main() {
	// iostream::sync_with_stdio(false);
	// cin.tie(0);

	/*
		1ª: definir o valor do vetor na posição i, para x, ou seja: vetor[i] = x;
		2ª: calcular o valor da soma no intervalo [l, r]
	*/

	int n, q, tipo, l, r;

	cin >> n >> q;

	vetor.resize(n);
	tree.resize(2*n);

	for(auto &el: vetor) cin >> el;

	build(0, n-1, 1);

	for(int i = 0; i < q; i++) {
		cin >> tipo >> l >> r;

		if(tipo == 1) {
			update(l, r, 0, n-1, 1);
		} else {
			cout << query(l, r, 0, n-1, 1) << endl;
		}
	}
	
    return 0;
}
 