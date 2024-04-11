#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for(int i = 0; i < nums.size(); i++) {
        numMap[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(numMap.count(complement) && numMap[complement] != i) {
            return {i, numMap[complement]};
        }
    }
    return {};
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {3,2,4};
    for(auto it : twoSum(nums, 6)) {
        cout << it << " ";
    }    
}