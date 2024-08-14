#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void numIslands_helper(vector<vector<char>>& grid, int row, int col) {
    grid[row][col] = '0';
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(auto direc : directions) {
        int newRow = row + direc.first;
        int newCol = col + direc.second;
        if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()
        && grid[newRow][newCol] == '1') {
            numIslands_helper(grid, newRow, newCol);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == '1') {
                count++;
                numIslands_helper(grid, i, j);
            }
        }
    }
    return count;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<vector<char>> grid = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
    };    
    // cout << grid.size() << " " << grid[0].size() << " ";
    // cout << grid[0][2];
    cout << numIslands(grid);
}