#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int minOperations(vector<int>& nums) {
    int count = 0;
    for(int i = 2; i < nums.size(); i++) {
        if(nums[i - 2] == 0) {
            nums[i - 2] =! nums[i - 2];
            nums[i - 1] =! nums[i - 1];
            nums[i] =! nums[i];
            count++;
        }
    }
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            return -1;
        }
    }
    return count;
}

int main()
{
// ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
//  #ifndef ONLINE_JUDGE
//    freopen("main.inp", "r", stdin);
//    freopen("main.out", "w", stdout);
// #endif
}