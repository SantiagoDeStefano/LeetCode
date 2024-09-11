#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void dfs(int row, int col, set<pair<int, int>>& visited, vector<vector<int>>& heights, int prevHeight) {
    if(visited.count({row, col}) || row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size() || heights[row][col] < prevHeight) {
        return;
    }
    visited.insert({row, col});
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(auto direc : directions) {
        int newRow = row + direc.first;
        int newCol = col + direc.second;
        dfs(newRow, newCol, visited, heights, heights[row][col]);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    set<pair<int, int>> atlantic;
    set<pair<int, int>> pacific;
    vector<vector<int>> result;

    int numRow = heights.size();
    int numCol = heights[0].size();
    for(int i = 0; i < numRow; i++) {
        dfs(i, 0, pacific, heights, heights[i][0]);
        dfs(i, numCol - 1, atlantic, heights, heights[i][numCol - 1]);
    }
    for(int j = 0; j < numCol; j++) {
        dfs(0, j, pacific, heights, heights[0][j]);
        dfs(numRow - 1, j, atlantic, heights, heights[numRow - 1][j]);
    }
    for(int i = 0; i < numRow; i++) {
        for(int j = 0; j < numCol; j++) {
            if(atlantic.count({i, j}) && pacific.count({i, j})) {
                result.push_back({i, j});
            }
        }
    }
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
}