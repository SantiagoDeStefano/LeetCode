#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for(auto x : strs) {
        string word = x;
        sort(word.begin(), word.end());
        mp[word].push_back(x);
    }
    vector<vector<string>> result;
    for(auto x : mp) {
        result.push_back(x.second);
    }
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<string> str = {"eat","tea","tan","ate","nat","bat"};
    for(const auto& x : groupAnagrams(str)) {
        for(auto pair : x) {
            cout << pair << " ";
        }
    }
}