#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void oragesRotting_helper(vector<vector<int>>& grid, int row, int col, int minute) {
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
        return;
    }
    if(grid[row][col] > 1 && grid[row][col] < minute) {
        return;
    }
    if(grid[row][col] == 0) {
        return;
    }
    grid[row][col] = minute;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(auto direc : directions) {
        int newRow = row + direc.first;
        int newCol = col + direc.second;
        oragesRotting_helper(grid, newRow, newCol, minute + 1);
    }
}

int orangesRotting(vector<vector<int>>& grid) {
    int time = 2;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 2) {
                oragesRotting_helper(grid, i, j, 2);
            }
        }
    }
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 1) {
                return -1;
            }
            time = max(time, grid[i][j]);
        }
    }
    return time - 2;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
    cout << orangesRotting(grid);
}