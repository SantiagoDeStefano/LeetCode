#include<iostream>
#include<vector>
#include<climits>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1; 

    while(low < high) {
        int mid = low + (high - low)/2;

        //  4    5   6   7   0   1   2 
        // low          mid         high
        // If the nums[mid] < nums[high] -> The minimum number is on the right side
        // If the nums[mid] > nums[high] -> The minimum number is on the left side
        if(nums[mid] > nums[high]) {
            low = mid;
        }
        else {
            high = mid + 1;
        }
    }
    return nums[low];
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {3,4,5,1,2};
    cout << findMin(nums);
}