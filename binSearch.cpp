#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    int m; cin >> m;
    int n; cin >> n;

    int a[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}