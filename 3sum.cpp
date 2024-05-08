#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

vector<vector<int>> threeSum(vector<int>& nums) {
    
    //Sort lại vì sẽ dùng 2 con trỏ
    sort(nums.begin(), nums.end());
    
    //Tạo một set chứa các vector, trong các vector đó có chứa kết quả 
    set<vector<int>> mySet;

    //Mỗi 3 số là một kết quả -> dùng vector để chứa
    //Có nhiều kết quả -> lưu các vector đó trong một vector khác
    vector<vector<int>> result;

    //nums = -4 -1 -1 0 1 2
    //        i  l        r
    //sum = nums[i] + nums[left] + nums[right]
    //Vì hiện tại sum đang < 0 -> phải tăng left lên vì đang sắp xếp tăng dần
    //nums = -4 -1 -1 0 1 2
    //        i     l     r
    //Tương tự đến khi nào sum == 0
    //Đối với trường hợp sum đang > 0 -> phải giảm right xuống vì sắp xết tăng
    //Tương tự đến khi nào sum == 0
    for(int i = 0; i < nums.size(); i++) {
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {

                //Insert cả 3 số vào một vector được lưu trong một set
                mySet.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
            } else if(sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    //Truy cập vào từng cái vector trong mySet
    for(auto triplets : mySet) {

        //Pushback các vector trong mySet vào các vector chứa các vector khác là result
        result.push_back(triplets);
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

    // Testing

    // vector<int> nums = {-1,0,1,2,-1,-4};
    // for(const auto& x : threeSum(nums)) {
    //     for(auto num : x) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }
}