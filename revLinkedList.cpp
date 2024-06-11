#include<iostream>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {

    //1->2->3
    ListNode *node = nullptr;

    while(head != nullptr) {
        ListNode* temp = head->next;
        //1->2->3
        //h  t
        
        head->next = node;
        //null<-1  2->3
        // n    h  t   

        node = head;
        //null<-1  2->3
        //      n  t  

        head = temp;
        //null<-1  2->3
        //      n  h  

    }
    //null<-1  2->3
    //      n  h  t    

    //null<-1<-2->3
    //      n  h  t

    //null<-1<-2  3
    //         n  h

    //null<-1<-2  3  (null)
    //         n  h    t    

    //null<-1<-2<-3  (null)
    //         n  h    t   

    //null<-1<-2<-3  (null)
    //            n    h              

    //Head đã là nullptr -> trả về node(node đầu tiên trong linked list)
    return node;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    //Testing

    int n;
    cin >> n;

    int value;
    cin >> value;

    ListNode *head = new ListNode(value);
    ListNode *current = head;

    for(int i = 2; i <= n; i++) {
        cin >> value;
        current->next = new ListNode(value);
        current = current->next;
    }


    ListNode *node = nullptr;
    while(head != nullptr) {
        ListNode* temp = head->next;
        head->next = node;
        node = head;
        head = temp;
    }

    while(current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }

    // ListNode *node1 = new ListNode(1);
    // ListNode *node2 = new ListNode(2);
    // ListNode *node3 = new ListNode(3);

    // node1->next = node2;
    // node2->next = node3;

    // ListNode *current = node1;
    // while(current != nullptr) {
    //     cout << current->val << " ";
    //     current = current->next;     
    // }
}