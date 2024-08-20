#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    vector<vector<int>> result;
    for(int i = 0; i < nums1.size(); i++) {
        minHeap.push({nums1[i] + nums2[0], {i, 0}});
    }
    while(!minHeap.empty() && result.size() < k) {
        auto top = minHeap.top();
        minHeap.pop();
        int index_1 = top.second.first;
        int index_2 = top.second.second;
        result.push_back({nums1[index_1], nums2[index_2]});
        if(index_2 + 1 < nums2.size()) {
            minHeap.push({nums1[index_1] + nums2[index_2 + 1], {index_1, index_2 + 1}});
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
    vector<int> n1 = {1,7,11};
    vector<int> n2 = {2,4,6};
    for(auto x : kSmallestPairs(n1, n2, 3)) {
        for(auto i : x) {
            cout << i << " ";
        } 
        cout << endl;
    }
}