#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int maxLength = 0;
    vector<int> result(n, 1);
    for(int i = n - 2; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(nums[j] > nums[i]) {
                result[i] = max(result[i], 1 + result[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        maxLength = max(maxLength, result[i]);
    }
    return maxLength;
}

int lengthOfLIS_(vector<int>& nums) {
    vector<int> result;
    for(int i = 0; i < nums.size(); i++) {
        if(result.empty() || result.back() < nums[i]) {
            result.push_back(nums[i]);
        }
        else {
            int index = binarySearch(result, nums[i]);
            result[index] = nums[i];
        }
    }
    return result.size();
}

int binarySearch(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums);
}