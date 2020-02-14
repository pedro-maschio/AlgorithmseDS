#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}
void bubbleSort(vector<int>& arr, int n) {
    int ok = 0;

    for(int i = 0; i < n && !ok; i++) {
        ok = 1;
        for(int j = 0; j < n-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                ok = 0;
            }
        }
    }
}

int main() {
    int n;

    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}