#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

bool isAnagram(string s, string t) {
    unordered_map<char, int> countMap;
    for(auto chuCai : s) {
        countMap[chuCai]++;
    }
    for(auto chuCai : t) {
        countMap[chuCai]--;
    }
    // for(const auto& pair : countMap) {
    //     cout << pair.first << " " << pair.second << endl;
    // }
    for(const auto& pair : countMap) {
        if(pair.second != 0) {
            return false;
        }
    }
    return true;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    str s, t;
    cin >> s;
    cin >> t;
    if(isAnagram(s, t)) {
        cout << "ok";
    } else {
        cout << "ko ok";
    }
}