#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void solveNQueens_helper(int row, int n, set<int>& cols, set<int>& mainDiag, set<int>& secDiag, vector<string>& board, vector<vector<string>>& result) {
    if(row >= n) {
        result.push_back(board);
        return;
    }
    for(int col = 0; col < n; col++) {
        if(cols.count(col) || mainDiag.count(row - col) || secDiag.count(row + col)) {
            continue;
        }
        cols.insert(col);
        mainDiag.insert(row - col);
        secDiag.insert(row + col);

        board[row][col] = 'Q';
        
        solveNQueens_helper(row + 1, n, cols, mainDiag, secDiag, board, result);

        cols.erase(col);
        mainDiag.erase(row - col);
        secDiag.erase(row + col);

        board[row][col] = '.';
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    set<int> cols, mainDiag, secDiag;
    solveNQueens_helper(0, n, cols, mainDiag, secDiag, board, result);
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<vector<string>> result = solveNQueens(4);
    for(auto i : result) {
        for(auto x : i) {
            cout << x << endl;
        }
        cout << endl;
    }
}