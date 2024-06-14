#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high) {
        int mid = low + (high - low)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
}