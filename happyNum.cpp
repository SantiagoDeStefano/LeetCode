#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int sumSquare(int n) {
    int sum = 0;
    while(n != 0) {
        int temp = n%10;
        sum += temp * temp;
        n = n/10;
    }
    return sum;
}

bool isHappy(int n) {
    int tortoise = sumSquare(n);
    int hare = sumSquare(sumSquare(n));
    while(tortoise != hare && hare != 1) {
        tortoise = sumSquare(tortoise);
        hare = sumSquare(sumSquare(hare));
    }
    return hare == 1;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
}