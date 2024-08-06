#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[n] = 1;
    dp[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        dp[i] = dp[i + 1] + dp[i + 2];
    }
    return dp[0];
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << climbStairs(n);
}