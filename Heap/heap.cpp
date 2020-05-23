#include <bits/stdc++.h>

#define ll long long
//#define N (ll)(1e6)
#define EPS (double)(1e-12)

using namespace std;

/*  A Heap provides look-up of the max/min-element in O(1), insertion
    in O(log N) and extraction of the max/min-element in O(log N).
    This implementation use the template facilities of C++ language
    to deal with any builtin type.
    This implementation is a max-heap.
*/
template<typename T>
class Heap {
    private:
        vector<T> arr;
        size_t N;

        size_t parent(int i) { return (i-1)/2; }
        size_t left(int i) { return 2*i+1; }
        size_t right(int i) { return 2*i+2; }

        void MaxHeapify(int i) {
            int l = left(i);
            int r = right(i);

            int greatest = i;
            if(l < N && arr[l] > arr[i])
                greatest = l;
            if(r < N && arr[r] > arr[greatest])
                greatest = r;
            if(greatest != i) {
                swap(arr[greatest], arr[i]);
                MaxHeapify(greatest);
            }
        }

    public:
        Heap(): N(0) {}

        size_t size() { return N; }

        bool empty() { return N == 0; }

        // Insert element x in the heap.
        void push(T x) {
            if(N == arr.size()) 
                arr.push_back(x);
            else
                arr[N] = x;
            
            int i = N;

            while(i && arr[parent(i)] < arr[i]) {
                swap(arr[parent(i)], arr[i]);
                i = parent(i);
            }
            N++; // increase size of the heap
        }

        // Returns the biggest/smallest element.
        T top() {
            if(empty())
                throw out_of_range("Empty heap!");
            return arr[0];
        }

        // Removes the biggest/smallest element.
        T pop() {
            if(empty())
                throw out_of_range("Empty heap!");
            
            T root = arr[0];
            arr[0] = arr[N-1];
            N--;

            MaxHeapify(0);

            return root;
        }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Heap<int> heap;

    int n, val;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> val;
        heap.push(val);
    }

    while(!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
    
    return 0;
}