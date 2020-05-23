// Name: Range Minimum Queries I
// https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>
 
// # DEFINES # //
#define ll long long
#define EPS 1e-9
const ll M = 1000000007;
using namespace std;
const ll N = 1e6;
int t[4*N];
int arr[N];
 
void build(int i, int l, int r) {
    if(l == r) {
        t[i] = arr[l];
    } else {
        int m = (l+r)/2;
 
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        t[i] = min(t[2*i], t[2*i+1]);
    }
}
 
/* 
    l and r = intervalo atual
    ql and qr = intervalo da query
*/
int query(int i, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) // if the node is within the query( ql -- l --- r -- qr)
        return t[i];
    if(qr < l || ql > r)
        return INT32_MAX;
    
    int mid = (r+l)/2;
    return min(query(2*i, l, mid, ql, qr), query(2*i+1, mid+1, r, ql, qr));
}
 
int main(){
 
 
    int n, q, l, r;
 
    cin >> n >> q;
 
    for(int i = 0; i < n; i++)
        cin >> arr[i];
 
    build(1, 0, n-1);
    
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, n-1, l, r) << endl;
    }
 
    return 0;
}