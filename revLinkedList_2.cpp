#include<iostream>
#include<stack>
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

void inputNode(ListNode *&head) {
    int n;
    cin >> n;

    int value;
    cin >> value;

    head = new ListNode(value);
    ListNode *current = head;

    for(int i = 2; i <= n; i++) {
        cin >> value;
        current->next = new ListNode(value);
        current = current->next;
    }
}

void printNode(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* result = new ListNode(0);
    result->next = head;
    ListNode *prev = result;
    for(int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }
    ListNode *current = prev->next;
    for(int i = 0; i < right - left; i++) {
        ListNode* temp = current->next;
        current->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    return head;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    ListNode* head;
    inputNode(head);
    reverseBetween(head, 2, 4);
    printNode(head);
}   