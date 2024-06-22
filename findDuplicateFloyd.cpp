#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

//Floyd’s Cycle Finding Algorithm
int findDuplicate(vector<int>& nums) {

    //The only duplicated number in a 1 sized vector
    if(nums.size() == 1) return nums[0];
    
    //Hare and tortoise must be in the same position initially
    int hare = nums[0];
    int tortoise = nums[0]; 
    
    while(true) {

        //The hare pointer moves two times and tortoise moves one time
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];

        //They will eventually land on the same number
        // 1, 3, 4, 2, 2
        // 1 -> 3 -> 2 --
        //           ↑   |
        //           |   |
        //           |   |
        //           4 <--     
        // hare == toroise == 4
        if(hare == tortoise) break;
    }

    //E.x for better explanation

    //   p
    // 0 -> 1 -> 2   
    //       ⇖   | 
    //       x ⇖ ↓ 
    //           3

    // p : distance(number of jumps) from nums[0] to values that start the cycle
    // x : distance from the hare == tortoise to the values that start the cycle
    // c : distance from 1 -> 2 -> 3 -> (number of jumps needed to complete the cycle)

    // Tortoise's distance = p + c - x
    // Hare's distance = p + c + c - x = p + 2c - x
    // 2Tortoise = Hare
    // p + c - x = p + 2c - x
    //     p     =     x

    // -> Needs a Turtle = nums[0] pointer since it takes p = x jumps to reach
    // same num(values that starts the cycle) with Tortoise = Hare pointer
    
    int turtle = nums[0];
    while(turtle != tortoise) {
        
        //Both pointer move one time
        turtle = nums[turtle];
        tortoise = nums[tortoise];
    }

    //Same value
    return turtle;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<int> nums = {3,3,3,3,3};
    cout << findDuplicate(nums);
}