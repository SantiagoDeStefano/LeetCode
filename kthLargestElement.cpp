#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int kthLargestElement(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < nums.size(); i++) {
        minHeap.push(nums[i]);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << kthLargestElement(nums, 2);
}