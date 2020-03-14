// https://www.hackerrank.com/challenges/reduced-string/problem

#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>

using namespace std; 


int main() {
    string s;

    cin >> s;

    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]) {
            s = s.substr(0, i-1) + s.substr(i+1);
            i = 0;
        }
    }

    if(s.size() == 0)
        cout << "Empty String" << endl;
    else 
        cout << s << endl;

    return 0; 
} 