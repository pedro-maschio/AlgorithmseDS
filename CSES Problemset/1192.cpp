// Name: Counting Rooms
// https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
 
// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9
 
using namespace std;
 
void dfs(vector<string> &grid, int i, int j, int n, int m) {
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '.')
        return;
    grid[i][j] = '#';
    int xV[4] = {-1, 0, 0, 1};
    int yV[4] = {0, 1, -1, 0};
 
    for(int k = 0; k < 4; k++) {
        dfs(grid, i+yV[k], j+xV[k], n, m);
    }
}
 
int countRooms(vector<string> &grid, int n, int m) {
    if(grid.size() == 0)
        return 0;
 
    int count = 0;
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.') {
                dfs(grid, i, j, n, m);
                count++;
            }
        }
    }
 
    return count;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
 
    cin >> n >> m;
 
    vector<string> grid(n);
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        grid[i] = s;
    }
    cout << countRooms(grid, n, m) << endl;
    
    return 0;
}