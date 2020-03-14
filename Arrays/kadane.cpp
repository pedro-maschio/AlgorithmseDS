#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;

    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0, temp = 0;

    for(int i = 0; i < n; i++) {
        temp += arr[i];

        ans = max(temp, ans);

        if(temp < 0)
            temp = 0;
    }

    cout << ans << endl;
    return 0;
}