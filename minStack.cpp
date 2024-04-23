#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {
        
    }
    
    //4, 6, 3, 2
    //(Giá trị bỏ vào stack, giá trị nhỏ nhất)
    //Bỏ vào 4 -> (4, 4)
    //Bỏ vào 6 -> (6, 4)
    //Bỏ vào 3 -> (3, 3)
    //Bỏ vào 2 -> (2, 2)    
    void push(int val) {
        if(s.empty()) s.push({val, val});
        else {
            s.push({val, min(val, s.top().second)});
        }
    }
    
    void pop() {
        if(!s.empty()) {
            s.pop();
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
}