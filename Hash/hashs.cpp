#include <bits/stdc++.h>

#define ll long long
#define M 10e9+7

using namespace std;


// Polynomial Rolling Hash Function for strings
long long compute_hash(string const &s) {
    const int p = 31;
    const int m = 1e9 + 9;  
    long long hash_value = 0;
    long long p_pow = 1;

    for(char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


/* Problem: Given a list of n strings Si, each no longer than m characters, 
find all the duplicate strings and divide them into groups. */ 

vector<vector<int>> group_identical_strings(vector<string> const &s) {
    vector<vector<int>> groups;
    int n = s.size();
    cout << "size: " << n << endl;

    vector<pair<long long, int>> hashes(n);

    for(int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    for(int i = 0; i < n; i++) {
        if(i == 0 || hashes[i].first != hashes[i-1].first) {
            // move down into the groups vector
            groups.emplace_back();
        }
        // if not moved down (equals hashs), keep adding in front
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

/*
    Problem: Given a string S of length n, consisting only of lowercase English letters, 
    find the number of different substrings in this string.
*/
int count_unique_substrings(string const &s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;

    vector<long long> p_pow(n); 
    p_pow[0] = 1;

    for(int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;
    
    vector<long long> h(n + 1, 0);
    for(int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i]-'a'+1)*p_pow[i]) % m;
    }
    int cnt = 0;

    for(int l = 1; l <= n; l++) {
        set<long long> hs;

        for(int i = 0; i <=n-l; i++) {
            long long cur_h = (h[i+l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1])%m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

int main() {
    int n;
    

    cin >> n;

    vector<string> vetor;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vetor.push_back(s);
    }
    vector<vector<int>> res = group_identical_strings(vetor);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}