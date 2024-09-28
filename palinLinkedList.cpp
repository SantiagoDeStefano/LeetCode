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

bool isPalindrome(ListNode* head) {
    stack<ListNode*> myStack;
    ListNode *current = head;
    while(current != nullptr) {
        myStack.push(current);
        current = current->next;
    }
    current = head;
    int stack_size = myStack.size();
    for(int i = 0; i < stack_size/2; i++) {
        if(current->val != myStack.top()->val) {
            return false;
        }
        current = current->next;
        myStack.pop();
    }
    return true;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    ListNode *head = new ListNode();
    inputNode(head);
    if(isPalindrome(head)) cout << "True";
    else cout << "False";
}   