#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> q;
    for(int i = 0; i < stones.size(); i++) {
        q.push(stones[i]);
    }
    while(q.size() > 1) {
        int stoneY = q.top();
        q.pop();
        int stoneX = q.top();
        q.pop();
        if(stoneX != stoneY) {
            q.push(stoneY - stoneX);
        }
    }
    if(q.empty()) return 0;
    else return q.top();
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> stone = {2,2};
    cout << lastStoneWeight(stone);
}