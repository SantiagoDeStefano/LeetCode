#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

bool checkInclusion(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();

    //Edge case
    if(n1 > n2) return false;
    
    //Vector to count frequencies of characters in 2 string
    vector<int> s1_count(26, 0);
    vector<int> s2_count(26, 0);

    //Initialize 2 windows
    for(int i = 0; i < n1; i++) {
        s1_count[s1[i] - 'a']++;
        s2_count[s2[i] - 'a']++;
    }

    //Best case
    if(s1_count == s2_count) return true;
    for(int i = n1; i < n2; i++) {

        //Check the frequencies of each character in a fixed windows 
        //Add new character to the windows 
        s2_count[s2[i] - 'a']++;
        //Remove old character from the windows
        s2_count[s2[i - n1] - 'a']--;

        //True if 2 vectors are the same
        if(s1_count == s2_count) return true;
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

    //Testing

    str s1 = "abc";
    str s2 = "eidbacoo";
    if(checkInclusion(s1, s2)) cout << "YES";
    else cout << "FALSE";
}