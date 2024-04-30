#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

// Input: board = 
// -------------------------------------->j (y)
// | ["5","3",".",".","7",".",".",".","."]
// | ["6",".",".","1","9","5",".",".","."]
// | [".","9","8",".",".",".",".","6","."]
// | ["8",".",".",".","6",".",".",".","3"]
// | ["4",".",".","8",".","3",".",".","1"]
// | ["7",".",".",".","2",".",".",".","6"]
// | [".","6",".",".",".",".","2","8","."]
// | [".",".",".","4","1","9",".",".","5"]
// ↓ [".",".",".",".","8",".",".","7","9"]
// i
//(x)

//Dùng hệ toạ độ (y, x) thay vì (x, y)

bool isValidSudoku(vector<vector<char>> board) {
    
    //R sẽ lấy size của vector chứa các vector<char>
    //1 vector sẽ chứa được nhiều vector<char>
    //Tức là độ dài của cột
    int R = board.size();

    //C sẽ lấy size của vector thứ 0 chứa các vector<char>
    //Tức là độ dài của hàng
    int C = board[0].size();

    //Khởi tạo các map mà trong 9 vị trí mỗi
    //Vị trí sẽ chứa unordered_map<char, int>
    unordered_map<char, int> row[9];
    unordered_map<char, int> col[9];
    unordered_map<char, int> box[9];

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {

            char ch = board[i][j];
            
            if(ch == '.') continue;
            
            //Row thứ i chứa ch (ở trường <char>) sẽ được kiểm tra > 0 và sau đó cộng thêm 1 (ở trường <int>)
            //Ban đầu row[i][ch] sẽ là 0, sau khi kiểm tra mới cộng thêm 1
            //Chưa có phần tử nào trước đó row[i][ch] sẽ là 0
            //Sau đó sẽ được đánh dấu bằng cách cộng thêm 1

            //Tương tự với col[i][ch]
            
            // -------------------------------------->j (y) 
            // | ["0","0","0","1","1","1","2","2","2"]
            // | ["0","0","0","1","1","1","2","2","2"]
            // | ["0","0","0","1","1","1","2","2","2"]
            // | ["3","3","3","4","4","4","5","5","5"]
            // | ["3","3","3","4","4","4","5","5","5"]
            // | ["3","3","3","4","4","4","5","5","5"]
            // | ["6","6","6","7","7","7","8","8","8"]
            // | ["6","6","6","7","7","7","8","8","8"]
            // ↓ ["6","6","6","7","7","7","8","8","8"]
            // i
            //(x)   
            //Với mỗi cột i, i sẽ được phân vùng ra 3 giá trị bằng phép toán (i/3)*3
            //Với mỗi i, giá trị của cả cột với hàng j tương ứng sẽ nhận 1 số giống nhau duy nhất
            //Lưu ý: i/3*3 = (i/3)*3   
            //Sau đó tương tự như row
            if(row[i][ch]++ > 0 || col[j][ch]++ > 0 || box[i/3*3 + j/3][ch]++ > 0) return false;
        }
    }
    return true;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    
    //Testing
    
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

     for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << i/3*3 + j/3 << " ";
        }
        cout << endl;
    }
    // if(isValidSudoku(board)) cout << "VALID";
    // else cout << "INVALID";

    // int R = board.size();       
    // int C = board[0].size();    
    
    // unordered_map<char, int> rows[9];
    // unordered_map<char, int> cols[9];
    // unordered_map<char, int> boxes[9];

    // for(int i = 0; i < R; i++) {
    //     for(int j = 0; j < C; j++) {
    //         char ch = board[i][j];//current cell
    //         cols[j][ch]++;
    //     }
    // }
    // for(int i = 0; i < 9; ++i) {
    //     cout << "Map " << i << ":" << endl;
    //     for(const auto& pair : cols[i]) {
    //         cout << pair.first << ": " << pair.second << endl;
    //     }
    //     cout << endl;
    // }

    // if(isValidSudoku(board)) cout << "VALID!";
    // else cout << "NOT VALID!";
    // int bigSum = 0;
    // int sum = 0;
    // for(const auto& x : board) {
    //     for(auto it : x) {
    //         if(it == '.') {
    //             continue;
    //         }
    //         it = it - '0';
    //         sum += it;
    //     }
    // }
    // char ch = '5';
    // int rows[9] = {0};
    // int cols[9] = {0};
    // ch = ch - '0';
    // rows[ch]++;
    // for(int i = 0; i < 9; i++) {
    //     cout << rows[i] << " ";
    // }
}