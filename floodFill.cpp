#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int, int>> q;
    set<pair<int, int>> coordinates; 
    q.push({sr, sc});
    coordinates.insert({sr, sc});

    int first_color = image[sr][sc];
    image[sr][sc] = color;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};   
    while(!q.empty()) {
        auto toa_do = q.front();
        int row = toa_do.first;
        int col = toa_do.second;
        q.pop();

        for(auto direc : directions) {
            int newRow = row + direc.first;
            int newCol = col + direc.second;
            if(newRow < 0 || newRow >= image.size() || newCol < 0 || newCol >= image[0].size()) {
                continue;
            }
            if(coordinates.count({newRow, newCol}) || image[newRow][newCol] != first_color) {
                continue;
            }
            else {
                coordinates.insert({newRow, newCol});
                image[newRow][newCol] = color;
                q.push({newRow, newCol});
            }
        }
    }
    return image;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    vector<vector<int>> images = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    vector<vector<int>> result = floodFill(images, 1, 1, 2);
    for(auto x : result) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}