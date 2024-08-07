#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
    
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) {
        return nums[n - 1];
    }
    vector<int> total(n);
    total[0] = nums[0];
    total[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++) {
        total[i] = max(total[i - 1], nums[i] + total[i - 2]);
    }        
    return max(total[n - 1], total[n - 2]);
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums);
}