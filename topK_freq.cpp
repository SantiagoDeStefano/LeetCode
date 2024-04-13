#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;
const ll NMAX = 1e6;
const ll lim = 1e18;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> countMap; //Hashmap đếm số
    vector<int> keys; //Vector chứa key trong hashmap -> dùng để truy ra giá trị
    vector<int> result; //Vector giá trị
    unordered_map<int, vector<int>> freq; //Hashmap chứa frequency của từng số
    
    //Đếm số lần xuất hiện của từng số trong nums
    for(auto num : nums) {
        countMap[num]++;
    }

    //Gộp những số có số lần xuất hiện giống nhau vào 1 vector
    //VD: nums = [1, 1, 4, 4, 2, 2, 2, 7, 7, 7, 7, 7, 5, 5, 5, 5]
    // freq = {
    //     "0" = "0";
    //     "1" = "0";
    //     "2" = {1, 4};
    //     "3" = {2};
    //     "4" = {5};
    //     "5" = {7};
    // }
    for(auto x : countMap) {
        int temp = x.first;
        freq[x.second].push_back(temp);
    }

    //Bỏ tất cả số lần xuất hiện vào vector keys
    for(const auto& pair : freq) {
        keys.push_back(pair.first);
    }
    
    //Sort lại vector key giảm dần
    sort(keys.begin(), keys.end(), greater<int>());

    //In ra k phần từ đầu tiên(là k phần tử lớn nhất) cùng với điều kiện
    //i < keys.size() tránh trường hợp k > keys.size()
    for(int i = 0; i < k && i < keys.size(); i++) {

        //Gán vector values với vị trí keys[i] trong hash map freq
        //Vị trí keys[i] trong hash map freq có vector chứa những giá trị int
        //Vector values sẽ có giá trị lớn thứ i trong số k giá trị lớn nhất cần trả về
        const vector<int>& values = freq[keys[i]];

        //result.end() là một it chỉ về ptử cuối cùng của vector result
        //Phần tử đầu tiên được insert vào sẽ là phần từ đầu tiên khi kết thúc insert
        //VD: Sau khi chạy hết vòng lặp, result = [{7}; {5}]
        result.insert(result.end(), values.begin(), values.end());

        //Ngăn ko cho in quá k số xuất hiện 
        //nhiều nhất khi nums = {4,1,-1,2,-1,2,3} (vẫn không hiểu tại sao)
        if (result.size() >= k) break;
    }
    return result;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    //Testing

    // map<int, int> hashTable; 
    vector<int> nums = {4,1,-1,2,-1,2,3};
    for(int value : topKFrequent(nums, 5)) {
        cout << value << " ";
    }
    cout << endl;
    // unordered_map<int, vector<int>> freq;
    // for(auto num : nums) {
    //     hashTable[num]++;
    // }
    // for(auto x : hashTable) {
    //     int temp = x.first;
    //     freq[x.second].push_back(temp);
    // }
    // for(const auto& x : freq) {
    //     cout << "So lan xuat hien: " << x.first << ", Values: ";
    //     for(auto value : x.second) {
    //         cout << value << " ";
    //     }
    //     cout << endl;
    // }
    // vector<int> keys1;
    // for(const auto& pair : freq) {
    //     keys1.push_back(pair.first);
    // }

    // sort(keys1.begin(), keys1.end(), greater<int>());

    // for(int i = 0; i < 3 && i < keys1.size(); i++) {
    //     int key = keys1[i];
    //     cout << "Key: " << key << ", Values: ";
    //     const vector<int>& values = freq[key];
    //     for(int value : values) {
    //         cout << value << " ";
    //     }
    //     cout << endl;
    // }

    // // for(const auto& pair : hashTable) {
    // //     if(pair.second == 5) {
    // //         cout << pair.first;
    // //     }
    // // }
    // for(auto pair : hashTable) {
    //     temp.push_back(pair.second);
    // }
    // sort(temp.begin(), temp.end());
    // for(int i = 0; i < 2; i++) {
    //     for(auto pair : hashTable) {
    //         if(pair.second == temp.back()) {
    //             cout << pair.first << " ";
    //             temp.pop_back();
    //         }
    //     }
    // }
}