#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++) {
        int low = 0;
        int high = m - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(matrix[i][mid] == target) return true;
            if(matrix[i][mid] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
    }
    return false;
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
    
    int target;

    for(int i = 0; i < m; i++) {
        int low = 0;
        int high = n - 1;
        while(low < high) {
            int mid = low + (high - low)/2;
            if(a[i][mid] == target) return true;
            if(a[i][mid] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
    }
    return -1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}