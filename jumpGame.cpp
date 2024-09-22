#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;
    for(int i = nums.size() - 2; i >= 0; i--) {
        if(i + nums[i] >= goal) {
            goal = i;
        }
    }
    if(goal == 0) return true;
    else return false;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {2,0};
    if(canJump(nums)) cout << "YES";
    else cout << "NO";
}