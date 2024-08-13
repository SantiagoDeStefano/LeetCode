#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int distributeCookies_helper(int index, vector<int>& tracking, vector<int>& cookies, int k) {
    if(index == cookies.size()) {
        int unfair = -1;
        for(auto x : tracking) {
            unfair = max(unfair, x);
        }
        return unfair;
    }
    int minUnfair = 10000001;
    for(int i = 0; i < k; i++) {
        tracking[i] = tracking[i] + cookies[index];
        minUnfair = min(minUnfair, distributeCookies_helper(index + 1, tracking, cookies, k));
        tracking[i] = tracking[i] - cookies[index];
    }
    return minUnfair;
}
int distributeCookies(vector<int>& cookies, int k) {
    vector<int> tracking(k, 0);
    return distributeCookies_helper(0, tracking, cookies, k);
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> cookies = {36597,70125,68220,4921};
    cout << distributeCookies(cookies, 2);
}