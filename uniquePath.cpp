#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

int uniquePaths(int m, int n) {
    vector<int> row(n, 1);
    for(int i = 0; i < m - 1; i++) {
        vector<int> newRow(n, 1);
        for(int j = n - 2; j >= 0; j--) {
            newRow[j] = newRow[j + 1] + row[j];
        }
        row = newRow;
    } 
    return row[0];
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    cout << uniquePaths(3, 7);
}