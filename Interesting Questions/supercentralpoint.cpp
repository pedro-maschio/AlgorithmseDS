//https://codeforces.com/problemset/problem/165/A
#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct Ponto {
    int x;
    int y;

    bool operator<(const Ponto &p) {
        if(x == p.x)
            return y < p.y;
        return x < p.x;
    }
};

int main() {
    int n;
    
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    Ponto pontos[n];
    for(int i = 0; i < n; i++) {
        cin >> pontos[i].x >> pontos[i].y;
    }
    sort(pontos, pontos+n);
        
    int p = 0;
    int flag1, flag2, flag3, flag4;
    for(int i = 0; i < n; i++) {
        flag1 = flag2 = flag3 = flag4 = 0;
        for(int j = 0; j < n; j++) {
            if(i != j) { // para não comparar o mesmo ponto
                if(pontos[j].x < pontos[i].x && pontos[j].y == pontos[i].y) 
                    flag1 = 1;
                if(pontos[j].x > pontos[i].x && pontos[j].y == pontos[i].y) 
                    flag2 = 1;
                if(pontos[j].x == pontos[i].x && pontos[j].y > pontos[i].y) 
                    flag3 = 1;
                if(pontos[j].x == pontos[i].x && pontos[j].y < pontos[i].y) 
                    flag4 = 1;
            }
        }
        if(flag1 && flag2 && flag3 && flag4)
            p++;
    }
    cout << p << endl;

    return 0;
}