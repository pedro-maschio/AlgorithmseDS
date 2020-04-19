// https://www.urionlinejudge.com.br/judge/pt/problems/view/1087
#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

void solve(int x1, int y1, int x2, int y2) {
    if(x1 == x2 && y1 == y2)
        cout << "0\n";
    else if((abs(x1 - x2) == abs(y1 - y2)) || (x1 == x2) || (y1 == y2))
        cout << "1\n";
    else {
        cout << "2\n";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2;

    while(cin >> x1 >> y1 >> x2 >> y2, !(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)) {
        solve(x1, y1, x2, y2);
    }

    return 0;
}