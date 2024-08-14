#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void islandsAndTreasure_helper(vector<vector<int>>& grid, int row, int col, int step) {
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1) {
        return;
    }
    if(grid[row][col] < step) {
        return;
    } 
    grid[row][col] = step;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(auto direc : directions) {
        int newRow = row + direc.first;
        int newCol = col + direc.second;
        islandsAndTreasure_helper(grid, newRow, newCol, step + 1);
    }
}

void islandsAndTreasure(vector<vector<int>>& grid) {
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 0) {
                islandsAndTreasure_helper(grid, i, j, 0);
            }
        }
    }
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    vector<vector<int>> grid = {
    {2147483647, -1, 0, 2147483647},
    {2147483647, 2147483647, 2147483647, -1},
    {2147483647, -1, 2147483647, -1},
    {0, -1, 2147483647, 2147483647}
    };
    islandsAndTreasure(grid);
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}