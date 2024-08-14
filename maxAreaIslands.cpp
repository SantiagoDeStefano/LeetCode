#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int maxAreaOfIsland_helper(vector<vector<int>>& grid, int row, int col) {
    int maxArea = 1;
    grid[row][col] = 0;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(auto direc : directions) {
        int newRow = row + direc.first;
        int newCol = col + direc.second;
        if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()
        && grid[newRow][newCol] == 1) {
            maxArea = maxArea + maxAreaOfIsland_helper(grid, newRow, newCol);
        }
    }
    return maxArea;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 1) {
                maxArea = max(maxArea, maxAreaOfIsland_helper(grid, i, j));
            }
        }
    }    
    return maxArea;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<vector<int>> grid = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << maxAreaOfIsland(grid);
}