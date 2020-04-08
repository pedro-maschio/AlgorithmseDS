// https://www.urionlinejudge.com.br/judge/pt/problems/view/1763
#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, string> mapa;
    mapa.insert(make_pair("brasil" ,"Feliz Natal!"));
    mapa.insert(make_pair("alemanha" ,"Frohliche Weihnachten!"));
    mapa.insert(make_pair("austria" ,"Frohe Weihnacht!"));
    mapa.insert(make_pair("coreia"  ,"Chuk Sung Tan!"));
    mapa.insert(make_pair("espanha"  ,"Feliz Navidad!"));
    mapa.insert(make_pair("grecia"  ,"Kala Christougena!"));
    mapa.insert(make_pair("estados-unidos"  ,"Merry Christmas!"));
    mapa.insert(make_pair("inglaterra"  ,"Merry Christmas!"));
    mapa.insert(make_pair("australia"  ,"Merry Christmas!"));
    mapa.insert(make_pair("portugal"  ,"Feliz Natal!"));
    mapa.insert(make_pair("suecia"  ,"God Jul!"));
    mapa.insert(make_pair("turquia"  ,"Mutlu Noeller"));
    mapa.insert(make_pair("argentina"  ,"Feliz Navidad!"));
    mapa.insert(make_pair("chile"  ,"Feliz Navidad!"));
    mapa.insert(make_pair("mexico"  ,"Feliz Navidad!"));
    mapa.insert(make_pair("antardida"  ,"Merry Christmas!"));
    mapa.insert(make_pair("canada"  ,"Merry Christmas!"));
    mapa.insert(make_pair("irlanda"  ,"Nollaig Shona Dhuit!"));
    mapa.insert(make_pair("belgica"  ,"Zalig Kerstfeest!"));
    mapa.insert(make_pair("italia"  ,"Buon Natale!"));
    mapa.insert(make_pair("libia"  ,"Buon Natale!"));
    mapa.insert(make_pair("siria"  ,"Milad Mubarak!"));
    mapa.insert(make_pair("marrocos"  ,"Milad Mubarak!"));
    mapa.insert(make_pair("japao"  ,"Merii Kurisumasu!"));

    string s;
    while(cin >> s) {
        if(mapa.find(s) == mapa.end())
            cout << "--- NOT FOUND ---" << endl;
        else 
            cout << mapa[s] << endl;
    }

    return 0;
}