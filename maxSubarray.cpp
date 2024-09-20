#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int maxSubArray(vector<int>& nums) {
    int currentSum = 0;
    int maxSum = nums[0];
    if(nums.size() == 1) {
        return maxSum;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(currentSum < 0) {
            currentSum = 0;
        }
        currentSum = currentSum + nums[i];
        if(currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    return maxSum;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
}
