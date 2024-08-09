#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

unordered_map<string, char> map = {
    {"1", 'A'}, {"2", 'B'}, {"3", 'C'}, {"4", 'D'}, {"5", 'E'}, {"6", 'F'},
    {"7", 'G'}, {"8", 'H'}, {"9", 'I'}, {"10", 'J'}, {"11", 'K'}, {"12", 'L'},
    {"13", 'M'}, {"14", 'N'}, {"15", 'O'}, {"16", 'P'}, {"17", 'Q'}, {"18", 'R'},
    {"19", 'S'}, {"20", 'T'}, {"21", 'U'}, {"22", 'V'}, {"23", 'W'}, {"24", 'X'},
    {"25", 'Y'}, {"26", 'Z'}, {"27", '#'}
};

//https://drive.google.com/file/d/1XQAsePa60hOkQBUJ7NQBok14_uIJiG9o/view?usp=sharing
int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1);

    if(s[0] == '0') {
        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        if(s[i - 1] != '0') {
            dp[i] = dp[i] + dp[i - 1];
        }
        if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6') ) {
            dp[i] = dp[i] + dp[i - 2];
        }
    }
    return dp[n];
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    string s = "226";
    cout << numDecodings(s);
}