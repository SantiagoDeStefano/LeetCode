#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int currAmount = 1; currAmount <= amount; currAmount++) {
        for(auto coin : coins) {
            if(currAmount - coin >= 0) {
                dp[currAmount] = min(dp[currAmount], 1 + dp[currAmount - coin]);
            } 
        }
    }    
    if(dp[amount] != amount + 1) return dp[amount];
    else return -1;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> coins = {2};
    cout << coinChange(coins, 3);
}