#include <bits/stdc++.h>
 
#define ll long long
#define EPS 1e-7
 
using namespace std;

int main() {
    int n, a;

    while(cin >> n >> a, n || a) {
        vector<double> arr(n);
        double l = 0, r = 1e4, m = 0, sum = 0;

        for(auto &el: arr) {
            cin >> el;

            sum += el;
        }

        if(sum == a) {
            cout << ":D" << endl;
            continue;
        } else if(sum < a) {
            cout << "-.-" << endl;
            continue;
        }

        while(fabs(r - l) >= EPS) {
            m = (r + l) / 2.0;
      
            sum = 0;
            for(auto el: arr) {
                if(el > m)
                    sum += el - m;
            }
            if(fabs(sum - a) <= EPS) {
                break;
            }
            
            /*
                since m represents the height, we increase the cutting line if
                sum surpass the required area
            */
            if(sum > a)
                l = m;
            else 
                r = m;
        }
        printf("%.4lf\n", m);
    }
}