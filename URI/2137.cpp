#include <bits/stdc++.h>

#define ll long long
#define M (ll)(1e9+7)

using namespace std;

int main(){
    int n;
    string s;
    
    while(cin >> n) {
        vector<string> strings(n);
        for(int i = 0; i < n; i++) {
            cin >> s;
            strings[i] = s;
        }
        sort(strings.begin(), strings.end());
        for(int i = 0; i < n; i++)
            cout << strings[i] << endl;
    }
    return 0;
}