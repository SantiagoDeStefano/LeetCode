#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    multiset<int> myMultiset;

    int soNguoi;
    int limit;
    int soThuyen = 0;
    
    cin >> soNguoi;
    cin >> limit;

    int banDau = limit;

    for(int i = 0; i < soNguoi; i++) {
        int element;
        cin >> element;
        myMultiset.insert(element);
    }

    for (const auto& elem : myMultiset) {
        if(limit - elem >= 0) {
            limit = limit - elem;
        } else {
            limit = banDau;
            soThuyen++;
            limit = limit - elem;
        }
    }   
    cout << soThuyen + 1;
}