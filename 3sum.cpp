#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-1; i++){
            int low = i+1, high = n-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    output.push_back({nums[i], nums[low], nums[high]});
                    int tempIndex1 = low, tempIndex2 = high;
                    while(low < high && nums[low] == nums[tempIndex1]) low++;
                    while(low < high && nums[high] == nums[tempIndex2]) high--;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    for(const auto& s : threeSum(nums)) {
        for(int num : s) {
            cout << num << " ";
        }
        cout << endl;
    }
//     set<vector<int>> s;
//     vector<int> v1 = {1, 2, 3};
//     vector<int> v2 = {2, 3, 4};
//     vector<int> v3 = {3, 4, 5};

//     s.insert(v1);
//     s.insert(v2);
//     s.insert(v3);

//     for(const auto& vec : s) {
//         for(int num : vec) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }
}