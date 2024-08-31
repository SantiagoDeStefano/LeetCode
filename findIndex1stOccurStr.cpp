#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int strStr(string haystack, string needle) {
    for (int i = 0; i <= haystack.length() - needle.length(); i++) {
        if (haystack.substr(i, needle.length()) == needle) {
            return i;
        }
    }
    return -1;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
}