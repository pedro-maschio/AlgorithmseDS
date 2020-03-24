#include <bits/stdc++.h>

#define ll long long 

using namespace std;

#define M 10e9+7

bool ehPalindromo(string s) {
    for(int i = 0; i < s.length()/2; i++)
        if(s[i] != s[s.length()-i-1])
            return false;
    return true;
}

// Complexity O(n^3)
string naiveApproach(string s) {
    string best_s = "";
    int n = s.length();
    int best_len = 0;

    for(int L = 0; L < n; L++) {
        for(int R = L; R < n; R++) {
            int len = R - L + 1;

            if(len > best_len && ehPalindromo(s.substr(L, len))) {
                best_s = s.substr(L, len);
                best_len = len;
            }
        }
    }
    return best_s;
}

string longestPalindrome(string s) {
    int best_len = 0;
    string best_s = "";
    int n = s.length();

    for(int mid = 0; mid < n; mid++) {
        for(int x = 0; mid - x >= 0 && mid + x < n; x++) {
            if(s[mid - x] != s[mid + x])
                break;

            int len = 2 * x + 1;

            if(len > best_len) {
                best_len = len;
                best_s = s.substr(mid - x, len);
            }
        }
    }

    for(int mid = 0; mid < n - 1; mid++) {
        for(int x = 0; mid - x + 1 >= 0 && mid + x < n; x++) {
            if(s[mid-x+1] != s[mid + x])
                break;
            int len = 2 * x;

            if(len  > best_len) {
                best_len = len;
                best_s = s.substr(mid-x+1, len);
            }
        }
    }

    return best_s;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    cin >> s;  
    
    cout << longestPalindrome(s) << endl;
    return 0;
}