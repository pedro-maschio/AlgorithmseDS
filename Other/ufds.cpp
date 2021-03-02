#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define N (ll)(1e6)
#define EPS (double)(1e-12)
#define INF (ll)(1e17)

class UFDS {
private:
    vector<int> size, ps;
public:
    UFDS(int n): size(n+1, 1), ps(n+1) {
        iota(ps.begin(), ps.end(), 0);
    }

    int find_set(int x) {
        return x == ps[x] ? x : (ps[x] = find_set(ps[x]));
    }
    
    bool same_set(int x, int y) {
        return find_set(x) == find_set(y);
    }

    void union_set(int x, int y) {
        if(same_set(x, y))
            return;
        int p = find_set(x);
        int q = find_set(y);
        
        if(size[p] < size[q])
            swap(p, q);
            
        ps[q] = p;
        size[p] += size[q];

    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


 
    return 0;
}