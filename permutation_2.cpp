#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int visit[21];
void permuteUnique_helper(int index, vector<int>& nums, vector<int>& permutation, set<vector<int>>& result) {
    if(index >= nums.size()) {
        result.insert(permutation);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(visit[i] == 1) continue;
        visit[i] = 1;
        permutation.push_back(nums[i]);
        permuteUnique_helper(index + 1, nums, permutation, result);
        visit[i] = 0;
        permutation.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int> permutation;
    set<vector<int>> result;
    vector<vector<int>> ans;
    permuteUnique_helper(0, nums, permutation, result);
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
}