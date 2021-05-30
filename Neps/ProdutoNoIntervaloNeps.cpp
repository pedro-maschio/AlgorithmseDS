#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
const ll INF = (ll)(1e18);
const ll MOD = 1000000007;
const ll MAX = 100000;
using namespace std;

 
vector<ll> tree, arr;

void build(int l, int r, int no) {
    if(l == r) {
        tree[no] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(l, mid, 2*no);
    build(mid+1, r, 2*no + 1);

    tree[no] = tree[2*no] * tree[2*no + 1];
}


ll query(int A, int B, int l, int r, int no) {
    if(B < l || r < A)
        return 1;
    if(l >= A && r <= B)
        return tree[no];

    int mid = (l + r)/2;

    ll minLeft = query(A, B, l, mid, 2*no);
    ll minRight = query(A, B, mid+1, r, 2*no+1);

    return minLeft * minRight;
}

void update(int id, int v, int l, int r, int no) {
    if(l == r) {
        tree[no] = v;
        return;
    }

    int mid = (l + r) / 2;

    if(id <= mid)
        update(id, v, l, mid, 2 * no);
    else 
        update(id, v, mid+1, r, 2 * no + 1);
    
    tree[no] = tree[2*no] * tree[2*no + 1];
}   

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    
    while(cin >> n >> k) {

        arr.resize(n);
        tree.resize(4 * n);

        for(int j = 0; j < n; j++) {
            int num; cin >> num;

            if(num > 0)
                arr[j] = 1;
            else if(num < 0)
                arr[j] = -1;
            else 
                arr[j] = 0;
        }

        build(0, n-1, 1);

 
        for(int j = 0; j < k; j++) {
            char tipo;
            int A, B;

            cin >> tipo >> A >> B;

            if(tipo == 'C') {
                if(B > 0)
                    B = 1;
                else if(B < 0)
                    B = -1;
                else 
                    B = 0;
                update(--A, B, 0, n-1, 1);
            } else {
                int ans = query(--A, --B, 0, n-1, 1);

                if(ans > 0) {
                    cout << "+";
                } else if(ans < 0)
                    cout << "-";
                else 
                    cout << "0";
            }
            
        }
        cout << endl;
    }

    return 0;
}

