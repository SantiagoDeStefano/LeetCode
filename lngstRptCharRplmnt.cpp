#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int characterReplacement(string s, int k) {
    unordered_map<char, int> maxFreq;
    int j = 0;
    int maxCharFreq = 0;
    int maxLength = 0;
    for(int i = 0; i < s.size(); i++) {
        
        //Character that would replace
        maxFreq[s[i]]++;
        maxCharFreq = max(maxCharFreq, maxFreq[s[i]]);
        
        //Keep track length of replaced character
        if((i - j + 1) - maxCharFreq > k) {
            maxFreq[s[j]]--;   
            j++; 
        }
        else {
            maxLength = max(i - j + 1, maxLength);
        }
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

    string s = "AABABBA";
    cout << characterReplacement(s, 1);
}