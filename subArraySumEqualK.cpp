#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int count = 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum = sum + nums[i];
        if(sum == k) {
            count++;
        }
        if(map.find(sum - k) != map.end()) {
            count = count + map[sum - k];
        }
        map[sum]++;
    }
    return count;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> sum = {3,4,7,2,-3,1,4,2};
    cout << subarraySum(sum, 7);
}