#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    vector<vector<int>> output;
    for(int i = 0; i < nums.size(); i++) {
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                s.insert({nums[i], nums[left], nums[right]});
                right--;
                left++;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    for(auto& triplets : s) 
        output.push_back(triplets);
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