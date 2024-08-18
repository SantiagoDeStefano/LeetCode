#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    stack<int> s;
    for(int i = 0; i < nums2.size(); i++) {
        while(!s.empty() && nums2[i] > nums2[s.top()]) {
            map[nums2[s.top()]] = nums2[i];
            s.pop();
        }
        s.push(i);
        map[nums2[i]] = -1;
    }
    for(int i = 0; i < nums1.size(); i++) {
        nums1[i] = map[nums1[i]];
    }
    return nums1;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    for(auto x : nextGreaterElement(nums1, nums2)) {
        cout << x << " ";
    }
}