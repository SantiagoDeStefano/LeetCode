#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

//Hãy suy nghĩ một cách đơn giản, thực tế.

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    
    //Đi cùng với pair dễ xác định hơn
    vector<pair<int, int>> pos_speed;
    stack<int> myStack;
    
    //Push các giá trị vào vector<pair<int, int>>
    for(int i = 0; i < position.size(); i++) {
        pos_speed.push_back({position[i], speed[i]});
    }
    
    //Sort vì vị trí của cars là tương đối, không ảnh hưởng đến kết quả khi sort
    sort(pos_speed.begin(), pos_speed.end());
    
    double maxTime = -1;

    //Example
    //        t = 2.33           t = 2               t = 3
    //         [3]                [5]                 [7]
    //----------|------------------|-------------------|-------------->

    //Vì thời gian của car[7] lâu hơn thời gian của car[5] -> 2 xe sẽ thành fleet
    //Tương tự với car[3]
    //Đi từ đầu đến cuối vì ta sẽ dễ dàng so sánh thời gian giữa các car với nhau hơn 
    for(int i = position.size() - 1; i >= 0; i--) {
        double time = (target - pos_speed[i].first) * 1.0 / pos_speed[i].second;
        
        //Bỏ qua car.time nhỏ hơn, chỉ lấy cái phía trước
        if(time > maxTime) {
            maxTime = time;
            
            //Có thể dùng một biến để đếm nhưng stack vẫn dùng được
            myStack.push(pos_speed[i].first);
        }
    }

    //Số fleet
    return myStack.size();        
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    // Testing

    // vector<int> position = {10,8,0,5,3};
    // vector<int> speed = {2,4,1,1,3};
    
    // stack<int> myStack;

    // vector<pair<int, int>> pos_speed;

    // int target = 12;

    // for(int i = 0; i < position.size(); i++) {
    //     pos_speed.push_back({position[i], speed[i]});
    // }

    // sort(pos_speed.begin(), pos_speed.end());

    // int count = 0;

    // double maxTime = -1;

    // for(int i = position.size() - 1; i >= 0; i--) {
    //     double time = (target - pos_speed[i].first) * 1.0 / pos_speed[i].second;
    //     if(time > maxTime) {
    //         maxTime = time;
    //         myStack.push(pos_speed[i].first);
    //     }
    // }

    // cout << myStack.size();

}