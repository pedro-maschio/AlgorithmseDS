#include <bits/stdc++.h>

#define ll long long
#define N (ll)(2*1e5)
#define EPS (double)(1e-12)
#define M (ll)(1e9+7)

using namespace std;

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

class MaxHeap {
public:
    int capacity, size, *harr;

    MaxHeap(int capacity) {
        this->capacity = capacity;
        harr = new int[capacity];
        size = 0;
    }

    int parent(int i) {
        return (i-1)/2;
    }
    int left(int i) {
        return 2*i+1;
    }
    int right(int i) {
        return 2*i+2;
    }

    int top() {
        return harr[0];
    }
    
    void push(int x) {
        if(size == capacity)
            return;
        size++;
        int i = size - 1;
        harr[i] = x;

        while(i != 0 && harr[parent(i)] < harr[i]) {
            swap(&harr[parent(i)], &harr[i]);
            i = parent(i);
        }
    }
    
    void decreaseKey(int i, int new_value) {
        harr[i] = new_value;

        while(i != 0 && harr[parent(i)] > new_value) {
            swap(&harr[parent(i)], &harr[i]);
            i = parent(i);
        }
    }

    void MaxHeapify(int i) {
        int l = left(i);
        int r = right(i);

        int greatest = i;

        if(l < size && harr[l] > harr[i])
            greatest = l;
        if(r < size && harr[r] > harr[greatest])
            greatest = r;
        if(greatest != i) {
            swap(&harr[greatest], &harr[i]);
            MaxHeapify(greatest);
        }
    }

    int pop() {
        if(size <= 0)
            return INT_MIN;
        else if(size == 1) {
            size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[size-1];
        size--;

        MaxHeapify(0);

        return root;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    MaxHeap teste(n);
    for(int i = 0; i < n; i++) {
        teste.push(rand()%10000000);
    }
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        cout << teste.pop() << endl;
    }

    


    return 0;
}