#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, m, t, sum;

    cin >> n >> m;
    map<int, int> tempos;
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < m; j++) {
            cin >> t;
            sum += t;
        }   
        tempos[sum] = i+1;
    }
    
    map<int, int>::iterator i;

    i = tempos.begin();

    cout << i->second << endl;
    i++;
    cout << i->second << endl;
    i++;
    cout << i->second << endl;
    return 0;
}