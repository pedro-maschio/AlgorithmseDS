// https://www.urionlinejudge.com.br/judge/pt/problems/view/2518
#include <bits/stdc++.h>

#define ll long long
#define M (ll)(1e9+7)

using namespace std;

int main(){
    double n, h, c, l;

    while(cin >> n) {
        cin >> h >> c >> l;

        double H = h/100.0;
        double C = c/100.0;
        double L = l/100.0;

        double hip = sqrt(C*C + H*H);
        double comprimento = hip * n;

        printf("%.4lf\n", (double)comprimento*L);
    }
    return 0;
}