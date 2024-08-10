#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

//Why i'm i even doing this, i'm so lost with my life, is it all worth it?
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size(), false);
    set<string> words(wordDict.begin(), wordDict.end());
    dp[0] = true;
    for(int i = 1; i <= s.size(); i++) {
        for(auto word : words) {
            int start = i - word.size();
            if(start >= 0 && dp[start] && s.substr(start, word.size()) == word) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    if(wordBreak(s, wordDict)) cout << "YES";
    else cout << "NO";
}