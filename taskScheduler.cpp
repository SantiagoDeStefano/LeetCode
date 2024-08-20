#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

// A   C   A   B   D   B
// 1   3   1   2   4   2
int leastInterval(vector<char>& tasks, int n) {
    priority_queue<int> maxHeap;
    queue<pair<int, int>> q;
    unordered_map<char, int> map;
    int time = 0;
    for(int i = 0; i < tasks.size(); i++) {
        map[tasks[i]]++;
    }
    for(auto pair : map) {
        maxHeap.push(pair.second);
    }
    while(!maxHeap.empty() || !q.empty()) {
        time++;
        if(!maxHeap.empty()) {
            int count = maxHeap.top() - 1;
            maxHeap.pop();
            if(count > 0) {
                q.push({count, time + n});
            }
        }
        if(!q.empty() && q.front().second == time) {
            maxHeap.push(q.front().first);
            q.pop();
        }
    }
    return time;
}   

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<char> c = {'A', 'B', 'A', 'B', 'D', 'B'};
    leastInterval(c, 0);
    // vector<int> charToNum;
    // for(auto x : c) {
    //     charToNum.push_back(x - 'A');
    // }
    // for(auto x : charToNum) {
    //     cout << x << " ";
    // }
}