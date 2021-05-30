#include <bits/stdc++.h>
 
#define ll long long
#define INF 1000000000
 
using namespace std;

void solve(vector<int>& arr, int l) {
    vector<int> psum(arr.size(), 0);

    psum[0] = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        psum[i] = psum[i-1] + arr[i];
    }

    ll ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(binary_search(begin(psum), end(psum), psum[i]+l)) {
            if(binary_search(begin(psum), end(psum), psum[i]+2*l)) {
                ans++;

            }
        }
    }

    cout << ans << endl;
}

int main() {
    int n;

    while(cin >> n) {
        vector<int> arr(n);

        ll sum = 0;
        for(auto &el: arr) {
            cin >> el;
            sum += el;
        }

        if(sum % 3) {
            cout << 0 << endl;
        } else {
            solve(arr, sum/3);
        }
    }
  
}
