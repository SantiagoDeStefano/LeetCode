#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int visited[21];
void permute_helper(int index, vector<int>& nums, vector<int> permutation, vector<vector<int>>& result) {
    
    //Base case
    if(index == nums.size()) {
        result.push_back(permutation);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {
        
        //Ignore the visited num
        if(visited[i] == 1) continue;

        //Mark the visited num
        visited[i] = 1;
        permutation.push_back(nums[i]);
        permute_helper(index + 1, nums, permutation, result);

        //Backtracking
        visited[i] = 0;
        permutation.pop_back();
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> permutation;
    permute_helper(0, nums, permutation, result);
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {1,2,3,4};
    for(auto x : permute(nums)) {
        for(auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}