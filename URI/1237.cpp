// https://www.urionlinejudge.com.br/judge/pt/problems/view/1237
// For more information on the algorithm used: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define M (ll) (1e9+7)

int LCSubStr(string X, string Y, int m, int n) {
    int LCSuff[m+1][n+1];

    int result = 0;

    // |x| = m, |y| = n
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                LCSuff[i][j] = 0;
            }

            else if(X[i-1] == Y[j-1]) {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            } else 
                LCSuff[i][j] = 0;
        }
    }
    return result;
}

int main() {
    string a, b;
    while(getline(cin, a)) {
        
        getline(cin, b);

        cout << LCSubStr(a, b, a.size(), b.size()) << endl;
    }

    return 0;
}