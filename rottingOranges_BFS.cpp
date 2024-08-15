#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int orangesRotting(vector<vector<int>>& grid) {
    int fresh = 0;
    int time = 0;
    queue<pair<int, int>> q;
    for(int r = 0; r < grid.size(); r++) {
        for(int c = 0; c < grid[0].size(); c++) {
            if(grid[r][c] == 1) {
                fresh++;
            }
            else if (grid[r][c] == 2){
                q.push({r, c});
            }
        }
    }
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};    
    while(!q.empty() && fresh > 0) {
        int q_size = q.size();
        for(int index = 0; index < q_size; index++) {
            pair<int, int> cell = q.front();
            int r = cell.first;
            int c = cell.second;
            q.pop();
            for(auto direc : directions) {
                int newRow = r + direc.first;
                int newCol = c + direc.second;
                if(newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] != 1) {
                    continue;
                }
                grid[newRow][newCol] = 2;
                q.push({newRow, newCol});
                fresh--;
            }
        }   
        time++;
    }
    if(fresh == 0) return time;
    else return -1;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << orangesRotting(grid);
}