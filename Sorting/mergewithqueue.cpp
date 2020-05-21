#include <bits/stdc++.h>

#define ll long long
#define N (ll)(2*1e5)
#define EPS (double)(1e-12)
#define M (ll)(1e9+7)

using namespace std;

void merge(vector<int>& arr, int l, int middle, int r) {
    queue<int> L, R;

    for(int i = l; i <= middle; i++)
        L.push(arr[i]);
    for(int i = middle+1; i <= r; i++)
        R.push(arr[i]);
    
    int i = l;
    while(!(L.empty() || R.empty())) {
        if(L.front() <= R.front())
            arr[i++] = L.front(), L.pop();
        else
            arr[i++] = R.front(), R.pop();
    }

    while(!L.empty()) 
        arr[i++] = L.front(), L.pop();
    while(!R.empty())
        arr[i++] = R.front(), R.pop();

}


void mergeSort(vector<int>& arr, int l, int r) {
    int middle;
    if(l < r) {
        middle = (l+r)/2;
        mergeSort(arr, l, middle);
        mergeSort(arr, middle+1, r);
        merge(arr, l, middle, r);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)      
        cout << arr[i] << " ";


    return 0;
}