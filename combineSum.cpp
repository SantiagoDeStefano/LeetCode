#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;


//https://drive.google.com/file/d/1riOU7ntZDfHi-2r1T2_XHxLZRip0_QZg/view?usp=sharing
void combinationSum_(vector<int>& nums, int index, int sum, int target, vector<int>& comb, vector<vector<int>>& result) {
    if(sum == target) {
        result.push_back(comb);
        return;
    }

    if(sum > target || index >= nums.size()) {
        return;
    }
    
    comb.push_back(nums[index]);
    combinationSum_(nums, index, sum + nums[index], target, comb, result);

    comb.pop_back();
    combinationSum_(nums, index + 1, sum, target, comb, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    combinationSum_(candidates, 0, 0, target, combination, result);
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> a = {2,3,5};
    for(auto x : combinationSum(a, 8)) {
        for(auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}