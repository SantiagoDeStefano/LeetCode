#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

bool dfs_diagram(int index, int col, int row, vector<vector<char>>& board, string word) {
    if(index == word.size()) {
        return true;
    }
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
        return false;
    }
    char temp = board[row][col];
    board[row][col] = '#';
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(auto direc : directions) {
        int newRow = row + direc.first;
        int newCol = col + direc.second;
        if(dfs_diagram(index + 1, newCol, newRow, board, word)) {
            return true;
        }
    }
    board[row][col] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(dfs_diagram(0, col, row, board, word)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<vector<char>> test = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    int cols = test[0].size();
    int rows = test.size();
    cout << test[rows-1][cols-1];
    cout << cols << " " << rows;
}