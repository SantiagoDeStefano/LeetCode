#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

vector<int> plusOne(vector<int>& digits) {
    for(int i = digits.size() - 1; i >= 0; i--) {
        if(digits[i] != 9) {
            digits[i] = digits[i] + 1;
            return digits;
        }
        digits[i] = 0;
        if(i == 0) {
            digits.insert(digits.begin(), 1);
            return digits;
        }
    } 
    return digits;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
}