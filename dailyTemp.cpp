#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

vector<int> dailyTemperatures(vector<int>& temperatures) {
    
    vector<int> result(temperatures.size(), 0);
    
    //Sử dụng stack để trỏ vào từng vị trí trong vector<int> temperatures
    stack<int> myStack;

    for(int i = 0; i < temperatures.size(); i++) {
        
        //Ta chỉ quan tâm đến những nhiệt độ lạnh hơn so với temperatures[i] 
        //temperatures = [73,74,75,71,69,72,76,73]
        //                            ↑
        // myStack = [2,3,4]
        // result = [1,1,0,0,0,0,0,0]
        while(!myStack.empty() && temperatures[i] > temperatures[myStack.top()]) {
            
            //Lấy index đầu tiên trong stack vì đó là index của nhiệt độ sau cùng lạnh hơn so với temp[i]
            int index = myStack.top();
            myStack.pop();

            //Truy cập đến vector<int> result và dùng i - index để cập nhật số ngày
            result[index] = i - index;
        }
        
        //push vào stack những vị trí trong vector
        myStack.push(i);
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