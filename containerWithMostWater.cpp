#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

int mostWater(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int max_water = 0;
    while(l != r) {
        max_water = max(max_water, (r - l) * min(height[l], height[r]));
        if(height[l] < height[r]) l = l + 1;
        else r = r - 1;
    }
    return max_water;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << mostWater(v);
}
