#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    vector<int> result;
    multiset<int> mySet;

    for (int i = 0; i < nums.size(); ++i) {
        mySet.insert(nums[i]);

        if(i - k >= 0) {
            mySet.erase(mySet.find(nums[i - k]));
        }

        if(mySet.size() >= k) {
            auto it = mySet.begin();
            advance(it, x - 1);
            if (*it >= 0) {
                result.push_back(0);
            } else {
                result.push_back(*it);
            }
        }
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
    vector<int> nums = {-3,1,2,-3,0,-3};
    for(auto x : getSubarrayBeauty(nums, 2, 1)) {
        cout << x << " ";
    }
}