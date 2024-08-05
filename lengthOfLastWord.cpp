#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int lengthOfLastWord(string s) {
    int i = s.size() - 1;
    int count = 0;
    while(i >= 0 && s[i] == ' ') {
        i--;
    }
    while(i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }
    return count;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    string s = "luffy is still joyboy";
    cout << lengthOfLastWord(s);
}