#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void subsetsWithDup_helper(int index, vector<int>& nums, vector<int>& sub, set<vector<int>>& result) {
    vector<int> temp;
    temp = sub;
    sort(temp.begin(),temp.end());
    result.insert(temp);
    for(int i = index; i < nums.size(); i++) {
        // Skip duplicates
        // if (i > index && nums[i] == nums[i - 1]) continue;
        sub.push_back(nums[i]);
        subsetsWithDup_helper(i + 1, nums, sub, result);    
        sub.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> result;
    vector<int> sub;
    vector<vector<int>> ans;
    subsetsWithDup_helper(0, nums, sub, result);    
    for(auto x : result) {
        ans.push_back(x);
    }
    return ans;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {1,2,2};
    for(auto x : subsetsWithDup(nums)) {
        for(auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}