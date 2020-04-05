#include <bits/stdc++.h>

using namespace std;
/*
    A Segment Tree is often represented as an array and support
    the sum in a given range as well as update of an element
    in O(log n) time;   
*/

int pegaMeio(int s, int e) {
    return s + (e-s)/2;
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {
    if(qs <= ss && qe >= se)
        return st[si];
    
    if(se < qs || ss > qe)  
        return 0;

    int mid = pegaMeio(ss, se);
    return getSumUtil(st, ss, se, qs, qe, 2*si+1) + getSumUtil(st, ss, se, qs, qe, 2*si+2);
}

int getSum(int *st, int n, int qs, int qe) {
    if(qs < 0 || qe > n-1 || qs > qe)
        return -1;
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {
    if(i < ss || i > se)
        return;
    
    st[si] = st[si] + diff;
    if(se != ss) {
        int mid = pegaMeio(ss, se);
        updateValueUtil(st, ss, se, i, diff, 2*si+1);
        updateValueUtil(st, ss, se, i, diff, 2*si+2);
    }
}

void updateValue(int arr[], int *st, int n, int i, int new_val) {
    if(i < 0 || i > n-1)
        return;
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
    if(ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = pegaMeio(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) + constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int *constructST(int arr[], int n) {
    int x = (int)(ceil(log2(n)));

    int max_size = 2 * (int)pow(2, x) - 1;

    int *st = new int[max_size];

    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}



int main() {
    int n;

    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    int *st = constructST(arr, n);

    int x = (int)(ceil(log2(n)));    
    int length = 2 * (int)pow(2, x) - 1;
    for(int i = 0; i < length; i++) {
        cout << st[i] << " ";
    }

    return 0;
}