#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int rob_helper(vector<int>& nums, int left, int right) {
    int maxRob = 0;
    int prevMaxRob = 0;
    for(int i = left; i <= right; i++) {
        int temp = max(prevMaxRob + nums[i], maxRob);
        prevMaxRob = maxRob;
        maxRob = temp;
    }
    return maxRob;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) {
        return nums[0];
    }
    return max(rob_helper(nums, 0, n - 2), rob_helper(nums, 1, n - 1));
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {1,2,3};
    cout << rob(nums);
}