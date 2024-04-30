#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

//vector<string> tokens = {"2","1","+","3","*"};
//Stack sẽ có tác dụng xếp các số lên, sau đó nếu có dấu "+", "-", "*", "/"
//Sẽ thực hiện phép toán tương ứng
//Stack sẽ như sau:
//1
//2
//Khi có dấu "+", "-", "*", "/" xuất hiện sẽ cho secondOperand = Stack.top() = 1 và Stack.pop() để truy cập vào số tiếp theo
//2
//firstOperand = Stack.top() = 2 và Stack.pop() rồi Stack.push(result = firstOperand "+", "-", "*", "/" secondOperand)
//Sau khi Stack.pop() firstOperand thì Stack.empty() == true -> sau khi Stack.push(result) thì Stack.top() sẽ là result cuối cùng
//-> return Stack.top()

int evalRPN(vector<string>& tokens) {
    stack<int> myStack;
    for(const auto& x : tokens) {
        
        if(x == "+") {

            int secondOperand = myStack.top();
            myStack.pop();

            int firstOperand = myStack.top();
            myStack.pop();

            int result = firstOperand + secondOperand;
            myStack.push(result);

        } else if(x == "-") {

            int secondOperand = myStack.top();
            myStack.pop();

            int firstOperand = myStack.top();
            myStack.pop();

            int result = firstOperand - secondOperand;
            myStack.push(result);

        } else if(x == "*") {

            int secondOperand = myStack.top();
            myStack.pop();

            int firstOperand = myStack.top();
            myStack.pop();

            int result = firstOperand * secondOperand;
            myStack.push(result);
            
        } else if(x == "/") {

            int secondOperand = myStack.top();
            myStack.pop();

            int firstOperand = myStack.top();
            myStack.pop();

            int result = firstOperand / secondOperand;
            myStack.push(result);

        } else {

            //Chuyển các số có dạng string về int
            myStack.push(stoi(x));
        }
    }
    return myStack.top();
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    // Testing

    // vector<string> tk = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    // stack<int> myStack;
    // // for(auto x : tk) cout << x << " ";
    // for(const auto& x : tk) {
    //     if(x == "+") {
    //         int secondOperand = myStack.top();
    //         myStack.pop();
    //         int firstOperand = myStack.top();
    //         myStack.pop();
    //         int result = firstOperand + secondOperand;
    //         myStack.push(result);
    //     } else if(x == "-") {
    //         int secondOperand = myStack.top();
    //         myStack.pop();
    //         int firstOperand = myStack.top();
    //         myStack.pop();
    //         int result = firstOperand - secondOperand;
    //         myStack.push(result);
    //     } else if(x == "*") {
    //         int secondOperand = myStack.top();
    //         myStack.pop();
    //         int firstOperand = myStack.top();
    //         myStack.pop();
    //         int result = firstOperand * secondOperand;
    //         myStack.push(result);
    //     } else if(x == "/") {
    //         int secondOperand = myStack.top();
    //         myStack.pop();
    //         int firstOperand = myStack.top();
    //         myStack.pop();
    //         int result = firstOperand / secondOperand;
    //         myStack.push(result);
    //     } else {
    //         myStack.push(stoi(x));
    //     }
    // }
    // cout << myStack.top();
}