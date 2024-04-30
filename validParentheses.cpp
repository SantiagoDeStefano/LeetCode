#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

bool isValid(string s) {
    stack<char> checkStack;
    for(auto x : s) {

        //Chỉ nhận ( [ { vào trong stack
        if(x == '(' || x == '[' || x == '{') {
            checkStack.push(x);

            //Nếu stack empty tức là string s chỉ có ) ] } -> không valid
        } else if(checkStack.empty()) {
            return false;
        } else {
            
            //string s = "[{()}]"
            //checkStack = [ { (
            //Khi x gặp ')' sẽ checkStack.pop() cái '(' thì last-in-first-out 
            //checkStack = [ { 
            //Tương tự với các dấu khác
            if(x == ')' && checkStack.top() != '(') return false;
            if(x == '}' && checkStack.top() != '{') return false;
            if(x == ']' && checkStack.top() != '[') return false;
            checkStack.pop();
        }
    }

    //checkStack.empty() == true -> string s hợp lệ vì checkStack.pop() sẽ loại tất cả 
    //Những 'Dấu mở ngoặc' có 'Dấu đóng ngoặc' liền kề
    //checkStack.empty() == false -> 'Dấu mở ngoặc' không có 'Dấu đóng ngoặc'
    return checkStack.empty();
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    //Testing

    string s = "[][]{{(}})";

    if(isValid(s)) cout << "VALID";
    else cout << "INVALID";

    stack<char> checkStack;
    // for(auto x : s) {
    //     if(x == '(' || x == '[' || x == '{') {
    //         checkStack.push(x);
    //     } else if(checkStack.empty()) {
    //         return false;
    //     } else {
    //         if(x == ')' && checkStack.top() != '(') return false;
    //         if(x == '}' && checkStack.top() != '{') return false;
    //         if(x == ']' && checkStack.top() != '[') return false;
    //     }
    //     checkStack.pop();
    // }
    // return true;
    // while (!checkStack.empty()) {
    //     cout << checkStack.top() << " ";
    //     checkStack.pop();
    // }
}