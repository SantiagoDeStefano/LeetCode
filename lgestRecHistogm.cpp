#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<pair<int, int>> s;
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int start = i;
        while(!s.empty() && s.top().second > heights[i]) {
            int index = s.top().first;
            int height = s.top().second;
            s.pop();
            maxArea = max(maxArea, height*(i - index));
            start = index;
        }
        s.push({start, heights[i]});
    } 
    while(!s.empty()) {
        maxArea = max(maxArea, s.top().second * (n - s.top().first));
        s.pop();
    }
    return maxArea;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> height = {2,1,5,6,2,3};
    cout << largestRectangleArea(height);
}

