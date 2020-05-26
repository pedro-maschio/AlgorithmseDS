#include <bits/stdc++.h>

#define ll long long
#define N (ll)(1e6)
#define EPS (double)(1e-12)
#define M (ll)(347)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    
    while(getline(cin, s)) {
        
        istringstream is(s);
        
        vector<string> vetor;
        string temp;
        while(is >> temp) {
            vetor.push_back(temp);
        }

        int i = 0;
        bool foi = false;
        int conta = 0;
        while(i < vetor.size() - 1) {
            foi = false;
            while(i < vetor.size()-1 && tolower(vetor[i][0]) == tolower(vetor[i+1][0])) {
                i++;
                foi = true;
            }
            if(foi) {
                conta++;
            } else {
                i++;
            }
        }
        cout << conta << endl;
    }

    return 0;
}