#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void selectionSort(vector<int>& arr, int n) {
    int minIndex;

    for(int i = 0; i < n; i++) {
        minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }   
        swap(arr[i], arr[minIndex]);
    }

}
int main() {
    int n;

    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    selectionSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}