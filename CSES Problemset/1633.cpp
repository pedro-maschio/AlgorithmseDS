// Name: Dice Combinations
// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
 
// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9
 
using namespace std;
 
int dp[(int)10e6];
void solve(int x) {
    
    dp[0] = 1;
 
    int dados[6] = {1, 2, 3, 4, 5, 6};
 
    for(int i = 1; i <= x; i++) {
        for(auto c : dados) {
            if(i-c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= M;
            }
        }
    }
    cout << dp[x] << endl;
}
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x;
 
    cin >> x;
 
    solve(x);
 
    return 0;
}