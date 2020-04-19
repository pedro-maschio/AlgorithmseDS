// https://www.urionlinejudge.com.br/judge/pt/problems/view/1743

#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)1e9+7
#define EPS 1e-9

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[5], b[5];

    bool compativel = true;

    for(int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 5; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < 5; i++) {
        if((a[i] ^ b[i]) == 0)
            compativel = false;
    }
    if(compativel)
        cout << "Y" << endl;
    else 
        cout << "N" << endl;


    return 0;
}