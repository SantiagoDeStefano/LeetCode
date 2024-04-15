#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

string encode(vector<string>& strs) {
    string result;
    for(int i = 0; i < strs.size(); i++) {
        string string = strs[i];
        result += to_string(string.size()) + "#" + string;
    }
    return result;
}

vector<string> decode(string s) {
    vector<string> result;
    int i = 0;
    while(i < s.size()) {
        int j = i;
        while(s[j] != '#') {
            j++;
        }
        int length = stoi(s.substr(i, j - i));
        string str = s.substr(j + 1, length);
        result.push_back(str);
        i = j + 1 + length;
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

    vector<string> input = {"neet","code","love","you"};

    for(auto x : decode(encode(input))) {
        cout << x << " ";
    }

    // vector<string> s = {"neet","code","love","you"};
    // string result;
    // for(int i = 0; i < s.size(); i++) {
    //     string str = s[i];
    //     result += to_string(str.size()) + "#" + str;
    // }

    // vector<string> result1;
    // int i = 0;
    // while(i < s.size()) {
    //     int j = i;
    //     while(result[j] != '#') {
    //         j++;
    //     }
    //     int length = stoi(result.substr(i, j - 1));
    //     string str = result.substr(j + 1, length);
    //     result1.push_back(str);
    //     i = j + 1 + length;
    // }
    // for(auto x : result1) {
    //     cout << x << " ";
    // }
}