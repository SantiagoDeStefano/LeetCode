#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void subsets_(int index, vector<int>& nums, vector<int>& subSet, vector<vector<int>>& result) {
    if(index >= nums.size()) {
        result.push_back(subSet);
        return;
    }

    //Add nums[i]
    subSet.push_back(nums[index]);
    subsets_(index + 1, nums, subSet, result);

    //Not add nums[i]
    subSet.pop_back();
    subsets_(index + 1, nums, subSet, result);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subSet;
    subsets_(0, nums, subSet, result);
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {1,2,3};
    for(auto x : subsets(nums)) {
        for(auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}