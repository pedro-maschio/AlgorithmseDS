// code for this challenge: https://www.hackerrank.com/challenges/max-array-sum/problem
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> arr) {
    if(arr.size() == 1)
        return arr[0];
    int current = arr[0];
    int global = 0;
    int global_new;

    for(int i = 1; i < arr.size(); i++) {
        global_new = max(global, current);

        current = global + arr[i];
        global = global_new;
    }
    return max(current, global);
}

int main() {
    int n;

    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxSubarraySum(arr) << endl;

    return 0;
}