#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

bool checkPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void partition_helper(string& s, int index, vector<string>& subPalind, vector<vector<string>>& result) {
    if(index >= s.size()) {
        result.push_back(subPalind);
        return;
    }
    string sub_string = "";
    for(int i = index; i < s.size(); i++) {
        sub_string = sub_string + s[i];
        if(checkPalindrome(sub_string)) {
            subPalind.push_back(sub_string);
            for(auto x : subPalind) {
                cout << x << " ";
            }
            cout << endl;
            partition_helper(s, i + 1, subPalind, result);
            subPalind.pop_back();
        }
    }
}

vector<vector<string>> partition(string& s) {
    vector<string> subPalind;
    vector<vector<string>> result;
    partition_helper(s, 0, subPalind, result);
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    string s = "aab";
    for(auto x : partition(s)) {
        for(auto i : x) {
            cout << " ";
        }
        cout << endl;
    }
}