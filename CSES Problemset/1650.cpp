// Name: Range Xor Queries
// https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>
 
#define ll long long
#define EPS (ll)(1e-10)
#define N (ll)(1e6)
using namespace std;
 
ll tree[(ll)(4*N)];
ll arr[N];
 
void build(ll i, ll l, ll r) {
    if(l == r) {
        tree[i] = arr[l];
    } else {
        ll middle = l + (r-l)/2;
 
        build(2*i+1, l, middle);
        build( 2*i+2, middle+1, r);
        tree[i] = tree[2*i+1]^tree[2*i+2];
    }
}
 
ll query(ll i, ll ql, ll qr, ll l, ll r) {
    if(ql <= l && qr >= r) {
        return tree[i];
    }
    if(ql > r || qr < l)
        return 0;
 
    ll middle = l + (r-l)/2;
 
    return query(2*i+1, ql, qr, l, middle)^query(2*i+2, ql, qr, middle+1, r);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll n, q, l, r;
 
    cin >> n >> q;
 
    for(ll i = 0; i < n; i++)
        cin >> arr[i];
 
    build(0, 0, n-1);
 
    for(ll i = 0; i < q; i++) {
        cin >> l >> r;
 
        cout << query(0, --l, --r, 0, n-1) << endl;
    }
 
    return 0;
}