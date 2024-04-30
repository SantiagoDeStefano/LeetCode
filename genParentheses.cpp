#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

//Sử dụng đệ quy để từ một trường hợp "(" sinh ra nhiều trường hợp khác

//O: opening, C: closing

//                                 ""   O-3, C-3
                                            
//                                 "(",O-2,C-3

                            //                         //

//             "((",O-1,C-3                            "()", O-2,C-2

            //              //                                //  

// "(((",0,3             "(()",1,2                       "()(",1,2

     //                 //          //                  //             //

// "((()",0,2      "(()(",0,2    "(())",1,1        "()((",0,2      "()()",1,1

// "((())",0,1     "(()()",0,1   "(())(",0,1       "()(()",0,1     "()()(",0,1

// "((()))",0,0   "(()())",0,0   "(())()",0,0      "()(())",0,0    "()()()", 0,0
                        
void genParen(string op, int open, int close, vector<string>& result) {
    
    //Với n cho trước, ta phải generate ra 3 "()" hợp lệ -> số "(" = số ")" = n
    //Đệ quy là nhiều nhánh gọi ra các nhánh khác cho nhau -> mỗi trường hợp if else là một nhánh khác nhau
    //Trong đệ quy luôn phải để trường hợp con nhỏ nhất lên đầu tiên và return -> tránh vòng lặp vô tận
    //return để khi hết dấu "(" và ")" -> kết thúc luôn một nhánh
    //Chỉ push_back khi không còn dấu "(" hay ")" -> chỉ có lúc đó mới hợp lệ
    if(open == 0 && close == 0) {
        result.push_back(op);
        return;
    }

    //Chỉ được thêm vào "(" vì chỉ khi đó mới hợp lệ
    
    //Marker #0
    
    if(open == close) {
    
        //Sử dụng một biến khác biến ban đầu để làm cái gốc
        string op1 = op;
        op1.push_back('(');

        //Bắt đầu rẽ nhánh với "("
        genParen(op1, open - 1, close, result);

                //Sẽ chỉ trình bày cách chạy 1 nhánh, các nhánh khác tương tự

                //Sẽ chạy xuống nhánh else vì các trường hợp kia đều không thoả mãn

                //Marker #1
                // else {
                //     string op1 = op;
                //     string op2 = op;
                //     op1.push_back('(');
                //     op2.push_back(')');
                //     genParen(op1, open - 1, close, result);
                //     genParen(op2, open, close - 1, result);
                // }

                //Rẽ ra 2 nhánh khác từ nhánh "(" là "((" và "()" nhưng nhánh "((" chạy trước
                //Vì nhánh "((" được đặt trước

                //Marker #2
                // else {
                //     string op1 = op;
                //     string op2 = op;
                //     op1.push_back('(');
                //     op2.push_back(')');
                //     genParen(op1, open - 1, close, result);
                //     genParen(op2, open, close - 1, result);
                // }

                //Tiếp tục rẽ ra nhánh "(((" và nhánh "(()" nhưng nhánh "(((" chạy trước

                //Chạy xuống nhánh này vì opening = 0, closing = 3 -> chỉ còn cách đóng ngoặc             
                //"(((" trở thành "((()"
                
                //Marker #3

                // } else if(open == 0) {
                //     string op1 = op;
                //     op1.push_back(')');
                //     genParen(op1, open, close - 1, result);

                //Lặp lại tương tự cho đến khi trở thành "((()))"

                //Return khi đã thoả điều kiện -> không còn cách nào khác
                
                //Marker #4

                // if(open == 0 && close == 0) {
                //     result.push_back(op);
                //     return;
                // }

                //Lý do return là quay trở lại tới Marker #1 và tiếp tục với genParen(op2)

                //Marker #0
                //    |
                //    |
                //    ---> Marker #1
                //             |
                //             |        
                //             ---> Marker #2 <-  
                //                     |       |
                //       Bắt đầu chạy genParen(op2) vì đã xong genParen(op1) (rẽ ra một nhánh khác)                          
                //                     |       |          
                //                     |       |            
                //                     ---> Marker #3      <-------
                //                                                |                
                //              Kết thúc hàm vì đã kết thúc nhánh (Marker #3)
                //                                                |
                //                             |                  |
                //                             |                  |
                //                             ---> Marker #4 (return)                

    //Chỉ có thể thêm dấu ")" vì đã hết dấu "("
    } else if(open == 0) {

        string op1 = op;
        op1.push_back(')');
        genParen(op1, open, close - 1, result);
    
    //Chỉ có thể thêm dấu "(" vì đã hết dấu ")"
    } else if(close == 0) {
        
        string op1 = op;
        op1.push_back('(');
        genParen(op1, open - 1, close, result);
    
    }
    else {

        string op1 = op;
        string op2 = op;

        op1.push_back('(');
        op2.push_back(')');

        //Rẽ ra một nhánh khác với dấu "("
        //Vì đã mất một dấu "(" nên phải trừ đi 1
        genParen(op1, open - 1, close, result);

        //Rẽ ra một nhánh khác với dấu ")"
        //Vì đã mất một dấu ")" nên phải trừ đi 1
        genParen(op2, open, close - 1, result);
    }
}

vector<string> generateParenthesis(int n) {
    
    int open = n;
    int close = n;
    
    vector<string> result;
    string op = "";
    
    genParen(op, open, close, result);
    return result;

}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    for(auto x : generateParenthesis(8)) {
        cout << x << endl;
    }
}