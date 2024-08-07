#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> total(n);
    total[n - 1] = cost[n - 1];
    total[n - 2] = cost[n - 2]; 
    for(int i = n - 3; i >= 0; i--) {
        total[i] = cost[i] + min(total[i + 1], total[i + 2]);
    }
    return min(total[0], total[1]);
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(cost);
}