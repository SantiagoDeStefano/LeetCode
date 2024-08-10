#include<iostream>
#include<vector>
#include <climits> 
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

double long maxProduct(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) {
        return nums[0];
    }
    double long maxProd = 0;
    double long maxLeft = 1;
    double long maxRight = 1;
    for(int i = 0; i < n; i++) {
        if(maxLeft == 0) maxLeft = 1;
        maxLeft = maxLeft*nums[i];
        maxProd = max(maxProd, maxLeft);
        
        if(maxRight == 0) maxRight = 1;
        maxRight = maxRight*nums[n - i - 1];
        maxProd = max(maxProd, maxRight);
    }
    return maxProd;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {-2,0,-1};
    cout << maxProduct(nums);
}