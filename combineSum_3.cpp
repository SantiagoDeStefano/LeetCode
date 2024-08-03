#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void combinationSum3_helper(int index, int k, int n, int currSum, vector<int>& subCombination, vector<vector<int>>& result) {
    if(currSum == n && subCombination.size() == k) {
        result.push_back(subCombination);
        return;
    }
    if(currSum > n || subCombination.size() > k) {
        return;
    }
    for(int i = index; i <= 9; i++) {
        subCombination.push_back(i);
        combinationSum3_helper(i + 1, k, n, currSum + i, subCombination, result);
        subCombination.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> subCombination;
    vector<vector<int>> result;
    combinationSum3_helper(1, k, n, 0, subCombination, result);
    return result;     
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    for(auto x : combinationSum3(3, 9)) {
        for(auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}