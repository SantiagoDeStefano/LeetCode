#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

bool isPalindrome(string s) {

    //Con trỏ left chạy từ đầu string
    int left = 0;

    //Con trỏ right chạy từ cuối string
    int right = s.size() - 1;

    while(left <= right) {

        //Bỏ qua nếu s[left] không phải là a b c x y z ...
        if(!isalnum(s[left])) {
            left++;
        }

        //Bỏ qua nếu s[right] không phải là a b c x y z ...
        else if(!isalnum(s[right])) {
            right--;
        }

        //So sánh s[left] và s[right] một khoảng như nhau
        else if(tolower(s[left]) != tolower(s[right])) {
            return false;
        } else {

            //Giảm khoảng so sánh trong string
            left++;
            right--;
        }
    }
    return true;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    // Testing

    string s = "race a car";

    if(isPalindrome(s)) cout << "YES";
    else cout << "NO";

    // string s; cin >> s;
    // int left = 0;
    // int right = s.size() - 1;

    // while(left <= right) {
    //     if(!isalnum(s[left])) {
    //         left++;
    //     }
    //     else if(!isalnum(s[right])) {
    //         right--;
    //     }
    //     else if(tolower(s[left]) != tolower(s[right])) {
    //         return false;
    //     } else {
    //         left++;
    //         right--;
    //     }
    // }
    // return true;
}