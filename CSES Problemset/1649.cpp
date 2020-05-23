// Name: Range Minimum Queries II
// https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>
 
using namespace std;
 
#define M (ll)(1e9+7)
#define EPS (double)(1e-12)
#define ll long long
#define N (ll)(2*1e5)
 
int arr[N];
int t[4*N];
 
void build(ll i, ll l, ll r) {
    if(l == r) {
        t[i] = arr[l];
    } else {
        ll m = (l+r)/2;
 
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        t[i] = min(t[2*i], t[2*i+1]);
    }
}
 
int minimo(ll i, ll l, ll r, ll ql, ll qr) {
    if(ql <= l && qr >= r)
        return t[i];
    if(ql > r || qr < l)
        return INT32_MAX;
 
    int m = (r+l)/2;
    return min(minimo(2*i, l, m, ql, qr), minimo(2*i+1, m+1, r, ql, qr));
}
 
void update(ll i, ll l, ll r, ll k, ll u) {
    if(l == r) {
        t[i] = u;
    } else {
        int mid = (l+r)/2;
 
        if(k <= mid) {
            update(2*i, l, mid, k, u);
        } else {
            update(2*i+1, mid+1, r, k, u);
        }
        t[i] = min(t[2*i], t[2*i+1]);
    }
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll n, q, l, r, type;
 
    cin >> n >> q;
 
    for(ll i = 0; i < n; ++i) 
        cin >> arr[i];
    build(1, 0, n-1);
 
    for(ll i = 0; i < q; ++i) {
        cin >> type >> l >> r;
        if(type == 1) {
            l--;
            update(1, 0, n-1, l, r);
        } else {
            cout << minimo(1, 0, n-1, --l, --r) << endl;
        }
    }
    
    return 0;
}