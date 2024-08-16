#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int findMaxLength(vector<int>& nums) {
    map<int, int> map;
    int prefixSum = 0;
    int maxLength = 0;
    map[0] = -1;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            prefixSum = prefixSum - 1;
        }
        else {
            prefixSum = prefixSum + 1;
        }
        if(map.find(prefixSum) != map.end()) {
            maxLength = max(maxLength, i - map[prefixSum]);
        }
        else {
            map[prefixSum] = i;
        }
    }
    return maxLength;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {0,1,1,0,0,1};
    cout << findMaxLength(nums);
}