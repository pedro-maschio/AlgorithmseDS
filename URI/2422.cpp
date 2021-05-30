#include <bits/stdc++.h>
 
#define ll long long
#define INF 1000000000
 
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    
    int n, k;

    cin >> n;

    vector<int> arr(n);

    for(auto &el: arr)
        cin >> el;
    cin >> k;

    for(int i = 0; i < n; i++) {
        if(binary_search(arr.begin(), arr.end(), k - arr[i])) {
            cout << arr[i] << " " << k - arr[i] << endl;
            break;
        }
    }
}