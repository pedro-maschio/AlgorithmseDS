// https://www.hackerrank.com/challenges/two-arrays/problem
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int main() { 
    int q, n, k, count;

    cin >> q;

    while(q--) {
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);
        count = 0;

        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++) 
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());

        for(int i = 0; i < n; i++) {
            if(a[i]+b[i] >= k) 
                count++;
            else 
                break;
        }
        if(count == n)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0; 
} 