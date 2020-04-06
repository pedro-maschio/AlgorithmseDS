// https://www.urionlinejudge.com.br/judge/pt/problems/view/2591
#include <bits/stdc++.h>

#define ll long long
#define M (ll)(1e9+7)

using namespace std;

int main(){
    ll n, s1, s2, i;
    string s;

    cin >> n;

    while(n--) {
        s1 = s2 = 0;
        i = 1;
        cin >> s;

        while(s[i] == 'a') {
            s1++;
            i++;
        }
        i += 3;
        while(s[i] == 'a') {
            s2++;
            i++;
        }
        i = 0;
        cout << "k";
        while(i < (s1*s2)) {
            cout << "a";
            i++;
        }
        cout << endl;

    }

    return 0;
}