// Name: Labyrinth
// https://cses.fi/problemset/task/1193/
#include <bits/stdc++.h>
 
#define ll long long
#define N (ll)(1e6)
#define EPS (double)(1e-12)
 
using namespace std;
 
bool found;
 
bool isSafe(vector<string>& grid, int i, int j, int n, int m) {
    if(i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#')
        return true;
    return false;
}
 
void reconstructPath(vector<string>& grid, map<pair<int, int>, pair<int, int>>& pred, pair<int, int> starting, pair<int, int> ending);
 
bool visited[1001][1001];
void checa(vector<string>& grid, int n, int m, pair<int, int> starting) {
   
    map<pair<int, int>, pair<int, int>> pred;
 
    queue<int> filai;
    queue<int> filaj;
    pair<int, int> ending;
 
    filai.push(starting.first);
    filaj.push(starting.second);
 
    int xV[4] = {-1, 0, 0, 1};
    int yV[4] = {0, 1, -1, 0};
 
    visited[starting.first][starting.second] = true;
 
    while(!filai.empty()) {
        int i = filai.front();
        int j = filaj.front();
        filai.pop();
        filaj.pop();
 
        if(grid[i][j] == 'B') {
            ending = {i, j};
            found = true;
            break;
        }
       
        for(int k = 0; k < 4; k++) {
            int in = i+yV[k];
            int jn = j+xV[k];
            if((in) >= 0 && (jn >= 0) && (in < n) && (jn < m) && (grid[in][jn] != '#') && !visited[in][jn]) {
                pred[{in, jn}] = {i, j};
                visited[in][jn] = true;
                filai.push(in);
                filaj.push(jn);
            }
        }
    }
 
    if(found) {
        cout << "YES" << endl;
        reconstructPath(grid, pred, starting, ending);
    } else {
        cout << "NO" << endl;
    }
}
 
void reconstructPath(vector<string>& grid, map<pair<int, int>, pair<int, int>>& pred, pair<int, int> starting, pair<int, int> ending) {
    string res;
 
    vector<pair<int, int>> path;
 
    for(auto a = ending; a != starting; a = pred[a]) {
        path.push_back({a.first, a.second});
    }
    path.push_back({starting.first, starting.second});
 
    reverse(path.begin(), path.end());
 
    for(int i = 1; i < path.size(); i++) {
        if(path[i].first > path[i-1].first)
            res.push_back('D');
        else if(path[i].first < path[i-1].first)
            res.push_back('U');
        else if(path[i].second > path[i-1].second)
            res.push_back('R');
        else if(path[i].second < path[i-1].second)
            res.push_back('L');
    }
    cout << path.size()-1 << endl;
    cout << res << endl;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
 
    pair<int, int> starting;
 
    cin >> n >> m;
 
    vector<string> grid;
    string s;
    
    for(int i = 0; i < n; i++) {
        cin >> s;
 
        for(int j = 0; j < m; j++) {
            if(s[j] == 'A')
                starting = {i, j};
        }
 
        grid.push_back(s);
    }
 
    checa(grid, n, m, starting);
    
 
    return 0;
}