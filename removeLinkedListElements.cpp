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

ListNode* removeElements(ListNode* head, int val) {
    ListNode *result = new ListNode(0);
    result->next = head;
    ListNode *current = result;
    while(current->next != nullptr && current != nullptr) {
        if(current->next->val == val) {
            current->next = current->next->next;            
        }
        else {
            current = current->next;
        }
    }   
    return result->next;
}

int main()
{
    ListNode *head = new ListNode();
    inputNode(head);
    removeElements(head, 7);
    printNode(head);
}   