#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

int maxArea(vector<int>& height) {
    
    //Sử dụng tham lam
    int left = 0;
    int right = height.size() - 1;
    int mostWater = 0;
    while(left < right) {
        
        //Tìm max sau mỗi lần tính
        //Độ dài = right - left, Độ cao = độ cao bé hơn giữa 2 cái
        mostWater = max(mostWater, (right - left) * min(height[left], height[right]));
        
        //height = [1,8,6,2,5,4,8,3,7]
        //Sử dụng tham lam -> từ 2 trường hợp cục bộ nhỏ nhất để suy ra cả bài
        if(height[left] < height[right]) left++;
        else right--;
    }
    return mostWater;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    // Testing

    // vector<int> height = {1,8,6,2,5,4,8,3,7};
    // cout << maxArea(height);
}