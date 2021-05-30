#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
const ll INF = 10000000000;
const ll MOD = 1000000007;
const ll MAX = 200010;
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    while(n--) {
        int num;

        cin >> num;

        ll ans = 0;
        for(ll i = 1; i*i <= num; i++) {
            if(num % i == 0) {
                ll b = num / i;
                ans += i;
                if(b != i)
                    ans += b;
            }
        }
        cout << ans << endl;
    }
}   