#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

bool containsDuplicate(vector<int>& nums) {
    map<int, int> countMap;
    for(int num : nums) {
        countMap[num]++;
    }
    for(const auto& pair : countMap) {
        if(pair.second >= 2) {
            return true;
        }
    }
    return false;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> v = {1, 2, 3, 1};
    if(containsDuplicate(v)) {
        cout << "Co duplicate";
    } else {
        cout << "Ko duplicate";
    }
    // map<int, string> myMap;
    // myMap.insert(make_pair(1, "One"));
    // myMap.insert(make_pair(2, "Two"));
    // myMap.insert(make_pair(3, "Three"));
    // cout << myMap[2] << endl;
    // for(auto it = myMap.begin(); it != myMap.end(); it++) {
    //     cout << it -> first << " " << it -> second << " ";
    // }
    // cout << endl;
    // auto findIt = myMap.find(4);
    // if(findIt != myMap.end()) {
    //     cout << findIt -> second << endl;
    // } else {
    //     cout << "Not found";
    // }
    // map<int, int> myMap;
    // int a[9] = {1, 2, 2, 2, 6, 4, 5, 8, 7};
    // for(int num : a) {
    //     myMap[num]++;
    // }
    // for(const auto& pair : myMap) {
    //     cout << pair.first << " " << pair.second << endl;
    // }
}