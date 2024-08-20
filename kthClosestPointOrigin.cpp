#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> minHeap;
    vector<vector<int>> result;
    for(auto point : points) {
        double distance = sqrt(point[0]*point[0] + point[1]*point[1]);
        minHeap.push({distance, point});
    }
    for(int i = 0; i < k; i++) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
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
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    for(auto x : kClosest(points, 2)) {
        for(auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}