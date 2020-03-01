#include <iostream> 
#include <vector>
#include <algorithm>
#include <climits>

using namespace std; 

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
 
class MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    public:
        MinHeap(int capacity);

        void MinHeapify(int );

        int parent(int i) { return (i-1)/2; }

        int left(int i) { return (2*i + 1); }

        int right(int i) { return (2*i + 2); }

        int findElement(int v);

        int extractMin();

        void decreaseKey(int i, int new_val);

        int getMin() { return harr[0]; }

        void deleteKey(int i);

        void insertKey(int k);
};

MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;

    harr = new int[cap];
}

void MinHeap::insertKey(int k) {
    if(heap_size == capacity) {
        cout << "Maximum size achieved!! Can't add more elements" << endl;
        return;
    }
    heap_size++;
    int i = heap_size - 1;

    harr[i] = k;

    while(i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}
// assumes that new_val is < than harr[i]
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;

    while(i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// find the index of a given element v. O(n) time -> improve it!!
int MinHeap::findElement(int v) {
    for(int i = 0; i < capacity; i++) {
        if(harr[i] == v)
            return i;
    }
    return -1;
}

int MinHeap::extractMin() {
    if(heap_size <= 0)
        return INT_MAX;
    if(heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);

    int smallest = i;

    if(l < heap_size && harr[l] < harr[i])
        smallest = l;
    if(r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if(smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }

}

int main() { 
    MinHeap h(11);

    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 

    cout << h.extractMin() << endl;
    cout << h.getMin() << endl;
    h.decreaseKey(2, 1);
    cout << h.getMin() << endl;

    return 0; 
} 