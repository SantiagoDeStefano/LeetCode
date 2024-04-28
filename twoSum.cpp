#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

vector<int> twoSum(vector<int>& numbers, int target) {
    
    int left = 0;
    int right = numbers.size() - 1;
    
    while(left < right) {
    
        if(numbers[left] + numbers[right] == target) {
            
            //Vì yêu cầu vị trí tính từ 1, 2, 3, 4, ... chứ không phải 0, 1, 2, 3, 4, ...
            return {left + 1, right + 1};
        }
        
        else if(numbers[left] + numbers[right] < target) {
            left++;
        
        } else {
            right--;
        }
    }
    return {-1, -1};
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    // Testing

    // vector<int> numbers1 = {2,3,4};
    // int target1 = 6;

    // for(auto x : twoSum(numbers1, target1)) {
    //     cout << x << " ";
    // }
}