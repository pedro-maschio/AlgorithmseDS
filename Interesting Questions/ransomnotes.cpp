// Question: https://www.hackerrank.com/challenges/ctci-ransom-note/problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int main() {
    int m, n, count = 0;
    string s;

    cin >> m >> n;

    map<string, int> a;
    map<string, int> b;
    vector<string> auxiliar1;
    vector<string> auxiliar2;

    for(int i = 0; i < m; i++) {
        cin >> s;
        auxiliar1.push_back(s);
        a[s]++;
    }
    for(int j = 0; j < n; j++) {
        cin >> s;
        auxiliar2.push_back(s);
        b[s]++;
    }
    for(int i = 0; i < n; i++) {
        if(b[auxiliar2[i]] <= a[auxiliar2[i]])
            count++;
    }
    if(count != n)
        cout << "No" << endl;
    else 
        cout << "Yes" << endl;


    return 0;
}

