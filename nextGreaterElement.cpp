#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

vector<int> nextGreaterElement(vector<int>& nums) {
    stack<int> s;
    vector<int> result(nums.size(), -1);
    for(int i = 0; i < nums.size(); i++) {
        while(!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
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
    vector<int> nums = {1,4,6,3,2,7};
    for(auto x : nextGreaterElement(nums)) {
        cout << x << " "; 
    }
}