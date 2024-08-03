#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

unordered_map<char, string> digitsToNum = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

void letterCombinations_helper(int index, unordered_map<char, string> digitsToNum, string digits, string currString, vector<string>& result) {
    if(currString.size() == digits.size()) {
        result.push_back(currString);
        return;
    }
    string possibleChar = digitsToNum[digits[index]];
    for(auto letter : possibleChar) {
        letterCombinations_helper(index + 1, digitsToNum, digits, currString + letter, result);
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.size() == 0) {
        return {};
    }
    vector<string> result;
    string currString = "";
    letterCombinations_helper(0, digitsToNum, digits, currString, result);
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    string digits = "23";
    for(auto x : letterCombinations(digits)) {
        cout << x << " ";
    }
}