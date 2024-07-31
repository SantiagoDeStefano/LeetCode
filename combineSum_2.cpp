#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void combinationSum2_helper(int index, int currSum, int target, vector<int>& candidates, vector<int>& sumSet, set<vector<int>>& result) {
    if(currSum == target) { 
        vector<int> temp;
        temp = sumSet;
        sort(temp.begin(), temp.end());
        result.insert(temp);
        return;
    }

    if(index >= candidates.size() || currSum > target) {
        return;
    }

    for(int i = index; i < candidates.size(); i++) {
        //Mark the duplicate element
        if(i > index && candidates[i] == candidates[i-1]) continue;
        sumSet.push_back(candidates[i]);
        combinationSum2_helper(i + 1, currSum + candidates[i], target, candidates, sumSet, result);
        sumSet.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    set<vector<int>> result;
    vector<int> sumSet;
    vector<vector<int>> ans;
    combinationSum2_helper(0, 0, target, candidates, sumSet, result);
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
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target; cin >> target;
    for(auto x : combinationSum2(candidates, target)) {
        for(auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}