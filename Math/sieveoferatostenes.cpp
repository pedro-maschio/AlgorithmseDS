#include <bits/stdc++.h>

#define ll long long
#define M 10e9+7

using namespace std;

bool isPrime(int n) {
    vector<bool> vetor(n+1, true);

    vetor[0] = vetor[1] = false;

    for(ll i = 2; i <= n; i++) {
        if(vetor[i]) {
            for(ll j = i * i; j <= n; j+= i) {
                vetor[j] = false;
            }
        }
    }
    return vetor[n];
}

int main() {
    int n;

    cin >> n;

    if(isPrime(n))
        cout << "Eh primooo!" << endl;
    else 
        cout << "Nao eh primoo!" << endl;

    return 0;
}