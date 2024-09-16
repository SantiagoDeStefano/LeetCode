#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void solve_helper(set<pair<int, int>>& coordinates, vector<vector<char>>& board, int row, int col) {
    if(row >= board.size() || row < 0 || col >= board[0].size() || col < 0) {
        return;
    }
    if(board[row][col] == 'X') {
        return;
    }
    if(coordinates.count({row, col})) {
        return;
    }
    coordinates.insert({row, col});
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(auto direc : direction) {
        int newRow = row + direc.first;
        int newCol = col + direc.second;
        solve_helper(coordinates, board, newRow, newCol);
    }
}

void solve(vector<vector<char>>& board) {
    set<pair<int, int>> notSurrounded;
    for(int i = 0; i < board.size(); i++) {
        if(board[i][0] == 'O') {
            solve_helper(notSurrounded, board, i, 0);
        }
        if(board[i][board[0].size() - 1]) {
            solve_helper(notSurrounded, board, i, board[0].size() - 1);
        }
    }
    for(int j = 0; j < board[0].size(); j++) {
        if(board[0][j] == 'O') {
            solve_helper(notSurrounded, board, 0, j);
        }
        if(board[board.size() - 1][j]) {
            solve_helper(notSurrounded, board, board.size() - 1, j);
        }
    }
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(notSurrounded.count({i, j}) == 0 && board[i][j] == 'O') {
                board[i][j] = 'X';
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
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    solve(board);
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}