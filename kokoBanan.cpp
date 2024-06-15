#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

bool hoursEatAble(vector<int>& piles, int k, int h) {
    int hours = 0;
    for(int pile : piles) {

        //If the pile/k == 1 -> accepted
        //If the pile/k < 1 -> should be 0
        //If the pile/k > 1 ->should be the interget of the division and will
        //Add one more hour with the below code
        int div = pile/k;
        hours += div;

        //If the pile%k != 0 -> should be count as 1 hour even if pile%k > 0 or < 0
        if(pile%k != 0) hours++;
    }

    //For finding the minimum k
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = 1000000000;

    while(low < high) {

        //Binary search the hour needed
        int mid = low + (high - low)/2;

        //If the condition of the hoursEatAble is true, ignore the larger k
        if(hoursEatAble(piles, mid, h)) high = mid;

        //If not, ignore the smaller k
        else low = mid + 1;
    }

    //Return the result as low == high == minimum k
    return high;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    // Testing

    vector<int> piles = {3,6,7,11};
    cout << minEatingSpeed(piles, 8);
}