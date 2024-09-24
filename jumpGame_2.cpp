#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int jump(vector<int>& nums) {
    int result = 0;
    int left = 0, right = 0;
    while(left < nums.size() - 1) {
        int max_jump = 0;
        for(int i = left; i <= right; i++) {
            max_jump = max(max_jump, i + nums[i]);
        }
        left = right + 1;
        left = max_jump;
        result++;
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
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums);
}