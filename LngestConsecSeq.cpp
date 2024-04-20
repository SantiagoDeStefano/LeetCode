#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;
ll a[NMAX + 10];

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    for(int num : nums) {
        set.insert(num);
    }
    int length = 0;
    for(int num : nums) {

        //Bắt đầu đếm từ giá trị bé nhất của nums thông qua set
        //Ví dụ nums = {100,4,200,1,3,2} thì set.find(99) hợp lệ, num = 100 sẽ được tính là 1 length nên gán curLength = 1
        //đồng thời được chạy xuống vòng while
        //Vì curNum = 100 + 1 = 101 không có trong set nên vòng for sẽ tiếp tục với num = 4
        //#1 set.find(4 - 1 = 3) == set.end() nên sẽ được tính là 1 length -> curLength = 1 và sẽ được chạy vòng for với length = 2 (curNum chạy từ 3 -> 4)
        //Sau khi kết thúc với num = 4, giá trị của num sẽ là num = 3 với set.find(3 - 1 = 2), lặp lại tương tự với num = 4
        //Lặp lại cho đến khi num = 1 (mục đích của dòng if(set.find(num - 1) == set.end()))
        //set.find(1-1 = 0) == set.end(), num = 1 (là giá trị bé nhất trong nums) sẽ được tính là 1 length -> curLength = 1 
        if(set.find(num - 1) == set.end()) {
            int curNum = num;
            int curLength = 1;

            //Bắt đầu đếm từ curNum + 1 (là curNum = 1 -> curNum + 1 = 2)
            while(set.find(curNum + 1) != set.end()) {
                
                //Tiếp tục tìm với curNum tiếp theo (curNum = curNum + 1 = 3)
                curNum++;

                //Tăng curLength lên 1 nếu tìm được curNum tiếp theo, và sẽ dừng ở curNum = 4 vì curNum = 4 + 1 = 5 không có
                //trong set 
                curLength++;
            }

            //Tìm max length mỗi khi num = (các số chưa phải nhỏ nhất) như dòng comment #1
            //Tránh trường hợp có nhiều đoạn consec trong 1 nums
            //VD: {100,4,200,1,3,300,1,2,5,2}
            length = max(length, curLength);
        }
    }
    return length;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    //Testing

    vector<int> nums = {1, 1, 1,1};
    
    cout << longestConsecutive(nums);

    // unordered_set<int> set;
    // for(int num : nums) {
    //     set.insert(num);
    // }
    // int length = 0;
    // for(int num : nums) {
    //     if(set.find(num - 1) == set.end()) {
    //         int curNum = num;
    //         int curLength = 1;
    //         while(set.find(curNum + 1) != set.end()) {
    //             curNum++;
    //             curLength++;
    //         }
    //         length = max(length, curLength);
    //     }
    // }
    // cout << length;

    // for(auto num : nums) {
    //     checkMap[num] = true;
    // }

    // for(auto x : checkMap) {
    //     cout << x.first << " " << x.second << endl;
    // }

    // cout << longestConsecutive(nums);

    // for(auto x : nums) {
    //     checkMap[x]++;
    // } 

    // // auto it = checkMap.find(100);
    // // if(it != checkMap.end()) cout << "YES";
    // // else cout << "NO";

    // int lenght = 1;
    // for(auto x : nums) {
    //     int nextNum = x + 1;
    //     auto it = checkMap.find(nextNum);       
    //     while((it != checkMap.end()) && (checkMap[nextNum] != 0)) {
    //         checkMap[nextNum] = 0;
    //         lenght++;
    //         nextNum++;         
    //     }
    //     int prevNum = x - 1;
    //     auto it_ = checkMap.find(prevNum);
    //     while((it_ != checkMap.end()) && (checkMap[prevNum] != 0)) {
    //         checkMap[prevNum] = 0;
    //         lenght++;
    //         prevNum--;
    //     }
    // }
    // cout << lenght - 1;
}
