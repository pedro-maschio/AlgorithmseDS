#include <bits/stdc++.h>
 
#define ll long long
#define endl '\n'
#define N (ll)(1e6)
#define EPS (double)(1e-6)
#define M (ll)(1e9+7)
#define INF (ll)(1e18)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
using namespace std;

struct Camiseta {
    string cor, nome;
    int tamanho;
};

int main() {    
    fastio;

    int n = 1;

    cin >> n;

    while(n) {
        
        Camiseta camisetas[n];
        string cor, tamanho, nome;
        cin.ignore();
        for(int i = 0; i < n; i++) {
            getline(cin, nome);

            cin >> cor >> tamanho;
            
            camisetas[i].nome = nome;
            camisetas[i].cor = cor;
            camisetas[i].tamanho = (tamanho == "P" ? 1 : tamanho == "M" ? 2 : 3);
            cin.ignore();
        }
        sort(camisetas, camisetas + n, [](const Camiseta &a, const Camiseta &b) {
            if(a.cor != b.cor)
                return a.cor < b.cor;
            else {
                if(a.tamanho != b.tamanho)
                    return a.tamanho < b.tamanho;
                else 
                    return a.nome < b.nome;
            }
        });

        for(auto a : camisetas) {
            cout << a.cor << " ";
            cout << (a.tamanho == 1 ? "P" : a.tamanho == 2 ? "M" : "G") << " ";
            cout << a.nome << endl;
        }
        cin >> n;
        if(n > 0)
            cout << endl;
    }


    return 0;   
}