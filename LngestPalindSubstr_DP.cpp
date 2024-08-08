#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

//https://drive.google.com/file/d/1aHTZq870jERREAKq4q5YSe_6810DOzEw/view
string longestPalindrome(string s) {
    int n = s.size();
    int left = 0;
    int right = 0;
    int maxLength = 0;
    string result = "";
    vector<vector<int>> checkBoard(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        checkBoard[i][i] = 1;
        for(int j = 0; j < i; j++) {
            if( (s[i] == s[j]) && (i - j + 1 <= 3 || checkBoard[j + 1][i - 1] == 1) ) {
                checkBoard[j][i] = 1;
                if(i - j + 1 > maxLength) {
                    maxLength = i - j + 1;
                    left = j;
                    right = i;
                }
            }
        }
    }
    for(int i = left; i <= right; i++) {
        result = result + s[i];
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
    string s = "babad";
    for(auto x : longestPalindrome(s)) {
        cout << x << " ";
    }
}