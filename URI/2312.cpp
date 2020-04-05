// https://www.urionlinejudge.com.br/judge/pt/problems/view/2312

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define M (ll) (1e9+7)

class Lista {
    public:
        string nome;
        int ouro, prata, bronze;    
};

// Used to order the struct
bool compare(const Lista &a, const Lista &b) {
    if(a.ouro == b.ouro && a.prata == b.prata && a.bronze == b.bronze)
        return a.nome > b.nome;
    else if(a.ouro == b.ouro && a.prata == b.prata)
        return a.bronze < b.bronze;
    else if(a.ouro == b.ouro)
        return a.prata < b.prata;
    else 
        return a.ouro < b.ouro;
}
 
int main() {
    int n;

    cin >> n;

    Lista lista[n];

    for(int i = 0; i < n; i++) {
        cin >> lista[i].nome >> lista[i].ouro >> lista[i].prata >> lista[i].bronze; 
    }
    sort(lista, lista + n, compare);

    for(int i = n-1; i >= 0; i--) {
        cout << lista[i].nome << " " << lista[i].ouro << " " << lista[i].prata << " " << lista[i].bronze;  
        cout << endl; 
    }

    return 0;
}