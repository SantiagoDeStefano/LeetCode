#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

long long maximumSubarraySum(vector<int>& nums, int k) {
    set<int> mySet;
    long long sum = 0;
    long long max_sum = 0;
    int j = 0;
    for(int i = 0; i < nums.size(); i++) {
        while(mySet.count(nums[i]) || mySet.size() == k) {
            sum = sum - nums[j];
            mySet.erase(nums[j]);
            j++;
        }
        mySet.insert(nums[i]);
        sum = sum + nums[i];
        if(mySet.size() == k) {
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {1,5,4,2,9,9,9};
    cout << maximumSubarraySum(nums, 3);
}