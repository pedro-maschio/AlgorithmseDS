/*
    Solution for the problem 1022 from URI Online Judge
    https://www.urionlinejudge.com.br/judge/pt/problems/view/1022
*/

#include <iostream>

#define ll long long
#define M 10e9+7

using namespace std;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    else 
        gcd(b, a % b);
}


void solve() {
    char ca;
    string s;

    ll a, b, c, d;
    char op1, op2, op3;

    cin >> a >> op1 >> b >> op2 >> c >> op3 >> d;
    ll num, den, res;


    if(op1 == '/' && op2 == '/' && op3 == '/') {
        num = a*d;
        den = b*c;

    } else if(op1 == '/' && op3 == '/') {
        den = b * d;
        if(op2 == '+') {
            num = (den/b)*a + (den/d)*c;
        }else if(op2 == '-') {
            num = (den / b)* a - (den/d)*c;
        } else 
            num = a * c;
    } else if(op2 = '/') {
        if(op1 == '*' && op3 == '*') {
            num = a * b;
            den = c * d;
        } 
    }

    // abs because of testcase (-2/8 = 1/-4) different from expected
    res = gcd(abs(num), abs(den));

    cout << num << "/" << den << " = ";
    cout << num/res << "/" << den/res << endl;

}

int main() {
   
    char a;
    ll t;

    
    cin >> t;
    cin.ignore();
    
    while(t--) {
        solve();
    }

    return 0;
}