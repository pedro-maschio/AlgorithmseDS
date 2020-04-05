// https://www.urionlinejudge.com.br/judge/pt/problems/view/2049
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define M (ll) (1e9+7)


int main() {
    ll flag, k = 0;
    string pat, text;

    cin >> pat;
    while(1) {
        k++;
        flag = 0; // to mark if already found the signature

        if(pat == "0") {
            break;
        }
        
        cin >> text;

        int T = text.size();
        int P = pat.size();
        for(int i = 0; i < T; i++) {
            int j = 0;
            if(text[i] == pat[j]) {
                 
                while(text[i] == pat[j] && i < T && j < P) {
                    i++;
                    j++;
                }  
                if(j == P) {
                    flag = 1;
                    break;
                }
            }
        }
        cout << "Instancia " << k << endl;
        if(flag)
            cout << "verdadeira" << endl;
        else 
            cout << "falsa" << endl;
        cin >> pat;
        if(pat != "0")
            cout << endl;
        else 
            break;
    }

    return 0;
}