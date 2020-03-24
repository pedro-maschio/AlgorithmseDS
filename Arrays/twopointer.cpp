#include <bits/stdc++.h>

using namespace std;

/*
    Given an array sorted in ascending order, having N integers, 
    find if there exists any pair of (A[i], A[j]) such that their
    sum is equals to X
*/

bool naive(int arr[], int n, int x) {

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] + arr[j] == x) {
                cout << "Encontrado em (" << i << ", " << j << ")!" << endl;
                return true;
            }
            if(arr[i] + arr[j] > x)
                break;
        }
    }
    cout << "Não encontrado!" << endl;
    return false;
}

bool twoPointers(int arr[], int n, int x) {
    int i = 0;
    int j = n - 1;

    while(i < j) {
        if(arr[i] + arr[j] == x) {
            cout << "Encontrado em (" << i << ", " << j << ")!" << endl;
            return true;
        } else if(arr[i] + arr[j] > x)  
            j--;
        else 
            i++;
    }

    return false;
}

int main() {
    int x, n;

    cin >> n >> x;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    twoPointers(arr, n, x);

}