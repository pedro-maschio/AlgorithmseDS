#include <bits/stdc++.h>

using namespace std;

long long int fibo[1000];

long long int fibonacci(long long int n) {
    if(n == 0 || n == 1)
        return n;
    else if(fibo[n]) {
        return fibo[n];
    } else {
        fibo[n] = fibonacci(n-1) + fibonacci(n-2);

        return fibo[n];
    }
}

int main() {
    long long int n;

    cin >> n;

    printf("%lld\n", fibonacci(n));

    return 0;
}