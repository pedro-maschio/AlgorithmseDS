// https://www.hackerrank.com/challenges/making-anagrams/problem

#include <iostream> 
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std; 

int freqa[26];
int freqb[26];
int main() {
    string a, b;
    int res = 0;

    cin >> a;
    cin >> b;

    for(int i = 0; i < a.size(); i++)   
        freqa[a[i]-'a']++;
    for(int j = 0; j < b.size(); j++) 
        freqb[b[j]-'a']++;

    for(int i = 0; i < 26; i++) {
        if(abs(freqa[i]-freqb[i]) != 0)
            res += abs(freqa[i]-freqb[i]);
    }
    cout << res << endl;


    return 0; 
} 