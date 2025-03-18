#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int longestNiceSubarray(vector<int>& nums) {
    int maxLength = 1;
    int left = 0;
    int usedBits = 0;    
    for(int right = 0; right < nums.size(); right++) {
        while((usedBits & nums[right]) != 0) {
            usedBits = usedBits^nums[left];
            left++;
        }
        usedBits = usedBits | nums[right];
        maxLength = max(maxLength, right - left + 1);
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
}