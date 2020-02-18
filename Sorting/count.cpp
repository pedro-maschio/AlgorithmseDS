#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define RANGE 256

void countSort(int arr[], int n) {
    int output[n];

    int count[RANGE+1], i;  
    memset(count, 0, sizeof(count));

    for(i = 0; i < n; i++)
        ++count[arr[i]];
    
    for(i = 1; i <= RANGE; i++) {
        count[i] += count[i-1];
    }

    for(i = 0; i < n; i++) {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;

    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    countSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
