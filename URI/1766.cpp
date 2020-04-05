// https://www.urionlinejudge.com.br/judge/pt/problems/view/1766
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define M (ll) (1e9+7)

struct Rena {
    string nome;
    int idade, peso;
    double altura;

    bool operator<(const Rena &r) {
        if(peso != r.peso) {
            return peso > r.peso;
        } else {
            if(idade != r.idade) {
                return idade < r.idade;
            } else if(idade != r.idade && altura != r.altura) {
                return altura < r.altura;
            } else {
                return nome < r.nome;
            }
        }
    }
};


int main() {
    ll t, n, m, peso, idade;
    double altura;
    string nome;

    cin >> t;

    
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        Rena renas[n];

        for(int i = 0; i < n; i++) {
            cin >> renas[i].nome >> renas[i].peso >> renas[i].idade >> renas[i].altura;
        }
        sort(renas, renas + n);

        cout << "CENARIO {" << (i+1) << "}" << endl;
        for(int i = 0; i < m; i++) {
            cout << (i+1) << " - " << renas[i].nome << endl;
        }
    }

    return 0;
}