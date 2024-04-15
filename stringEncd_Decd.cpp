#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

//Input = ["neet","code","love","you"]

//Sẽ cho một kí tự đặc biệt giữa các string trong vector<string>
//s = "neet#code#love#you#" //Gặp s[i] == '#' -> push_back những chữ trước dấu #
//Tuy nhiên không có dữ liệu sẽ push_back từ đâu đến đâu
//-> Phải có s[i].size() trước từng dấu #
//Cách này sẽ bao gồm trường hợp có dấu đặc biệt nào giữa trong những string
//VD: Input = ["neet","co#de","love","you#"]

string encode(vector<string>& strs) {
    string result;
    
    //Đưa vector<string> strs về dạng (size của string)#(string)
    for(int i = 0; i < strs.size(); i++) {
        string string = strs[i];
        
        //to_string chuyển từ int -> string
        result += to_string(string.size()) + "#" + string;
    }

    //Result sẽ có dạng 4#neet4#code4#love3#you
    return result;
}

vector<string> decode(string s) {
    vector<string> result;

    int i = 0;
    while(i < s.size()) {
        int j = i;
        
        //j sẽ chạy tới khi tới dấu # đầu tiên, trong khi i vẫn ở s[0]
        //4 # n e e t 4 # c o d e 4 # l o v e 3 # y o u
        //i
        //  j
        while(s[j] != '#') {
            j++;
        }
        
        //Đưa string -> int với s.substr(giá trị con trỏ i -> dấu #) tức là
        //size của từng string trong vector<string>
        //|4 |# n e e t 4 # c o d e 4 # l o v e 3 # y o u
        //i 
        //  j 
        int length = stoi(s.substr(i, j - i));

        //Lấy sub string từ (dấu #) + 1 đến hết string hiện tại
        //4 # |n e e t |4 # c o d e 4 # l o v e 3 # y o u
        //i 
        //  j x - - > x 
        string str = s.substr(j + 1, length);

        result.push_back(str);

        //4 # n e e t 4 # c o d e 4 # l o v e 3 # y o u
        //i 
        //  j
        // -->
        //4 # n e e t 4 # c o d e 4 # l o v e 3 # y o u
        //            i
        //  j
        //Sau đó j tiếp tục chạy đến s[j] == '#' và lặp lại đến khi hết s
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

    // Testing

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