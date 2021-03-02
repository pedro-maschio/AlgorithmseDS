#include <bits/stdc++.h>
 
#define ll long long
#define EPS 1e-7
 
using namespace std;

int main() {

    
    int n, k;

    while(cin >> n >> k, n || k) {

        map<int, int> mapeamento;
        vector<int> chega(n), sai(n);

        for(int i = 0; i < n; i++) {    
            cin >> chega[i] >> sai[i];

            mapeamento[sai[i]] = chega[i];
        }

        sort(begin(chega), end(chega));
        sort(begin(sai), end(sai));

        int i = 0, j = 0;
        bool possible = true;
        stack<int> estaciona;
        while(i < n || j < n) {
            if(i < n && j < n && chega[i] < sai[j]) {
                estaciona.push(chega[i]);
                i++;

                if(estaciona.size() > k) {
                    
                    possible = false;
                    break;
                }

            } else {
                if(!estaciona.empty() && mapeamento[sai[j]] != estaciona.top()) {
                    possible = false;

                    break;
                } else if(!estaciona.empty()) {
                    estaciona.pop();
                }
                
                j++;
            }
            
        }

        cout << (possible ? "Sim" : "Nao") << endl;
    }