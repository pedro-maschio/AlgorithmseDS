// Name: Range Sum Queries II
// https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
 
using namespace std;
 
#define M (ll)(1e9+7)
#define EPS (double)(1e-12)
#define ll long long
#define N (ll)(2*1e5)
 
ll t[(ll)4*N];
ll arr[(ll)N];
 
void build(ll i, ll l, ll r) {
    if(l == r) {
        t[i] = arr[l];
    } else {
        ll mid = (r+l)/2;
        build(i*2, l, mid);
        build(i*2+1, mid+1, r);
        t[i] = t[2*i] + t[2*i+1];
    }
}
 
 
ll sum(ll i, ll l, ll r, ll ql, ll qr) {
    if(ql <= l && qr >= r)
        return t[i];
    if(l > qr || r < ql)
        return 0;
    ll mid = (l+r)/2;
 
    return sum(2*i, l, mid, ql, qr) + sum(2*i+1, mid+1, r, ql, qr);
}
 
void update(ll v, ll l, ll r, ll k, ll u) {
    if(l == r) {
        t[v] = u;
    } else {
        ll mid = (l+r)/2;
 
        if(k <= mid)
            update(v*2, l, mid, k, u);
        else 
            update(v*2+1, mid+1, r, k, u);
        t[v] = t[v*2]+t[v*2+1];
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
        
        if(type == 2) {
            l--, r--;
            cout << sum(1, 0, n-1, l, r) << endl;
        } else {
            l--;
            update(1, 0, n-1, l, r);
        }
    }
 
    return 0;
}