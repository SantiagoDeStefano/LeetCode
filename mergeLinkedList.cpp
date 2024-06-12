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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    //Create a dummy that will store the merged list with the first element is 0
    ListNode *dummy = new ListNode(0);

    //A pointer to move through out the dummy
    ListNode *current = dummy;

    //Two pointer method
    while(list1 && list2) {
        if(list1->val > list2->val) {
            current->next = list2;
            list2 = list2->next;
        }
        else {
            current->next = list1;
            list1 = list1->next;
        }
        current = current->next;
    }

    //If one list is empty, the dummy will get all other elements
    if(list1 != nullptr) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }
    return dummy->next;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    //Testing

    ListNode *linked_list1 = new ListNode;
    inputNode(linked_list1);
    printNode(linked_list1);

    ListNode *linked_list2 = new ListNode;
    inputNode(linked_list2);
    printNode(linked_list2);    

    //Ignore above
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    ListNode *head1 = linked_list1;
    ListNode *head2 = linked_list2;

    while(head1 && head2) {
        if(head1->val > head2->val) {
            current->next = head2;
            head2 = head2->next;
        }
        else {
            current->next = head1;
            head1 = head1->next;
        }
        current = current->next;
    }
    if(head1 != nullptr) {
        current->next = head1;
    }
    else {
        current->next = head2;
    }

    printNode(dummy->next);
}   