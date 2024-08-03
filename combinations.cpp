#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

void combine_helper(int n, int k, int index, vector<int>& subCombine, vector<vector<int>>& result) {
    if(subCombine.size() == k) {
        result.push_back(subCombine);
        return;
    }
    if(subCombine.size() > k) {
        return;
    }
    for(int i = index; i <= n; i++) {
        subCombine.push_back(i);
        combine_helper(n, k, i + 1, subCombine, result);
        subCombine.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> subCombine;
    vector<vector<int>> result;
    combine_helper(n, k, 1, subCombine, result);
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif  
    for(auto x : combine(4, 2)) {
        for(auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}