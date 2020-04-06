// https://www.urionlinejudge.com.br/judge/pt/problems/view/1110
#include <bits/stdc++.h>

#define ll long long
#define M (ll)(1e9+7)

using namespace std;

int main(){
    int n;
    
    while(1) {
        cin >> n;
        if(n == 0)  
            break;

        deque<int> lista(n);
        vector<int> descartadas;
        int restante;
        iota(lista.begin(), lista.end(), 1);

        while(lista.size() > 1) {
            descartadas.push_back(lista.front());
            lista.pop_front();
            int topo = lista.front();
            lista.push_back(topo);
            lista.pop_front();
        }
        n = descartadas.size();
        cout << "Discarded cards: ";
        for(int i = 0; i < n; ++i) {
            cout << descartadas[i];
            if(i != n-1)
                cout << ", "; 
        }
        cout << endl;
        cout << "Remaining card: " << lista.front() << endl;

    }
    return 0;
}