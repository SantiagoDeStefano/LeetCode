#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int getPrice = prices[0];
    for(int i = 1; i < prices.size(); i++) {

        //Keep the lowest buy price possible
        if(prices[i] < getPrice) {
            getPrice = prices[i];
        }
        
        profit = max(profit, prices[i] - getPrice);
    }
    return profit;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices);
}