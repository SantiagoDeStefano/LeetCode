#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int lengthOfLongestSubstring(string s) {

    //Keep track of distinct character
    set<char> mySet;

    //Slower pointer
    int j = 0;
    int maxLength = 0;
    for(int i = 0; i < s.size(); i++) {
        
        //Found the same character -> move j to the same index
        //With i to start find the longest subStr again
        while(mySet.find(s[i]) != mySet.end()) {
            mySet.erase(s[j]);
            j++;
        }

        //Insert distinct character
        mySet.insert(s[i]);
        maxLength = max(maxLength, i - j + 1);
    }
    return maxLength;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    //Testing

    string s = "abcabcdbb";
    set<char> mySet;
    int j = 0;
    int maxLength = 0;
    for(int i = 0; i < s.size(); i++) {
        if(mySet.find(s[i]) != mySet.end()) {
            mySet.erase(s[i]);
            j++;
        }
        mySet.insert(s[i]);
        maxLength = max(maxLength, i - j + 1);
    }
    cout << maxLength;
}