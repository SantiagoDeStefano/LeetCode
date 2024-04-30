#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

vector<int> productExceptSelf(vector<int>& nums) {

    //Sử dụng quy hoạch động thay vì tính tích rồi chia lại cho các phần tử trong nums
    //Dúng cách kia sẽ làm code có nhiều ngoại lệ vd như: {2, 0}; {1, 0}; {0, 0};

    //Chứa các phần tử tích tăng dần của nums và left_product 
    vector<int> left_product(nums.size());

    //Chứa các phần tử tích giảm dần của nums và right_product
    vector<int> right_product(nums.size());

    //Giá trị nhỏ nhất = 1
    left_product[0] = 1;
    for(int i = 1; i < nums.size(); i++) {
        left_product[i] = left_product[i-1] * nums[i-1];
    }

    //Giá trị cuối vector = 1
    right_product[nums.size() - 1] = 1;
    for(int i = nums.size() - 2; i >= 0; i--) {
        right_product[i] = right_product[i+1] * nums[i+1];
    }

    //Tích các số xung quanh nhân lại với nhau
    for(int i = 0; i < nums.size(); i++) {
        nums[i] = left_product[i] * right_product[i];
    }
    return nums;

    //Sử dụng quy hoạch động thông qua suy luận, không có phương pháp cụ thể
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    
    //Testing
    
    vector<int> nums = {-1,1,0,-3,3};
    for(auto x : productExceptSelf(nums)) {
        cout << x << " ";
    }
}