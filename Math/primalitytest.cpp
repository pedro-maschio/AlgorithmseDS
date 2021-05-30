#include <bits/stdc++.h>

using namespace std;

#define ll long long 

/*
    We check only until sqrt(n). A composite number can be factored as n = a * b
    if a * b >= n, it means that both of them are bigger than sqrt(n). So, if 
    n is composite at least one factor MUST be less than sqrt(n).
*/
bool isPrime(int n) {
    if(n == 2)
        return true;
    for(int d = 2; d*d <= n; d+= 2)
        if(n % d == 0)
            return false;

    return true;
}

int main() {
    int n;
    cin >> n;

    if(isPrime(n))
        cout << "eh primo" << endl;
    else 
        cout << "nao eh primo" << endl;

    return 0;
}