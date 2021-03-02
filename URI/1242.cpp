#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
#define N (ll)(1e6)
#define EPS (double)(1e-10)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;


bool combinam(char a, char b) {
  
    if((a == 'C' && b == 'F') || (a == 'B' && b == 'S') || (a == 'F' && b == 'C') || (b == 'B' && a == 'S'))
        return true;
    return false;
}

int main() {    
    fastio;

    string s;


    while(cin >> s) {
        int ans = 0;
        stack<char> pilha;
        for(auto &c : s) {  
            if(!pilha.empty() && combinam(pilha.top(), c)) {
                pilha.pop();
                ans++;
            } else {
                pilha.push(c);
            }
        }
        cout << ans << endl;
    }
    return 0;   
}