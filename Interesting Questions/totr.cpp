// https://www.codechef.com/problems/TOTR
#include <iostream> 
#include <vector>
#include <map>
#include <ctype.h>

using namespace std; 

int main() { 
    int t, l, r, count;
    string m;

    cin >> t >> m;

    // <dialogue, m>  
    map<char, char> mapa;

    char a = 'a';
    for(int i = 0; i < m.size(); i++) {
        mapa.insert(pair<char, char>(a+i, m[i]));
    }

    while(t--) {
        string s;

        cin >> s;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '_')
                cout << " ";
            else if(s[i] >= 'a' && s[i] <= 'z') 
                cout << mapa[s[i]];
            else if(s[i] >= 'A' && s[i] <= 'Z') 
                cout << (char)toupper(mapa[tolower(s[i])]);
            else 
                cout << s[i];
            
        }
        cout << endl;
    }

    return 0; 
} 