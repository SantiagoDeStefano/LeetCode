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

ListNode* swapPairs(ListNode* head) {
    ListNode* result = new ListNode(0);
    result->next = head;
    ListNode* prev = result;
    while(head != nullptr && head->next != nullptr) {
        ListNode* first = head;
        ListNode* second = head->next;
        prev->next = second;
        first->next = second->next;
        second->next = first;
        prev = first;
        head = first->next;
    }
    return result->next;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    ListNode* list = new ListNode;
    inputNode(list);
    printNode(swapPairs(list));
}   