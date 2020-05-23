// Name: Range Sum Queries I
// https://cses.fi/problemset/task/1646/
#include <bits/stdc++.h>
 
// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9
 
using namespace std;
 
const long long N = 1e6; 
long long t[4*N];
 
void build(long long a[], long long v, long long tl, long long tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        long long tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
 
long long sum(long long v, long long tl, long long tr, long long l, long long r) {
    if(l > r) 
        return 0;
    if(l == tl && r == tr) {
        return t[v];
    }
    long long tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
 
 
int main(){
    ios::sync_with_stdio(0);
 
    long long  n, q, l, r;
 
    cin >> n >> q;
 
    long long  arr[n];
    for(long long  i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(arr, 1, 0, n-1);
 
    for(long long  i = 0; i < q; i++) {
        cin >> l >> r;
        long long  res = sum(1, 0, n-1, l-1, r-1);
        cout << res << endl;
    }
    return 0;
}