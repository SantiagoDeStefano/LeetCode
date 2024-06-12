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

void reorderList(ListNode* head) {

    //Use another pointer for the head in the list
    ListNode *current = head;

    //The stack with the parameter ListNode* and the argument is address
    stack<ListNode*> myStack;

    //The stack will be the reverse of the list
    //List = 1 2 3 4 5
    //Stack 
    //  =
    //  5
    //  4
    //  3
    //  2
    //  1
    while(current) {
        myStack.push(current);
        current = current->next;
    }

    //Reset the current pointer to the first of the list
    current = head;
    int size = myStack.size();

    //Only move to half of the stack
    for(int i = 0; i < size/2; i++) {

        // 1 2 3 4 5
        // c
        //Disconnect the 1 element and 2 element of the list
        //Let the myStack.top() point to the next element of the list
        // 5 -> 2
        myStack.top()->next = current->next;
        
        //Connect the current(1) element to the top element
        //Which is connected to the 2 element of the list
        // 1 -> 5 -> 2
        current->next = myStack.top();
        
        //Move the current to the next two element
        // 1 -> 2 ->  3 ->  4 ->  5
        // c
        // 1 ->  5 ->  2 ->  3 ->  4 ->  5
        //             c
        current = current->next->next;

        //Pop to access the below element of the stack
        myStack.pop();
    }
    
    //Disconnect the list when reordered the list
    // 1 ->  5 ->  2 ->  4 ->  3 -> NULL ->  5
    current->next = NULL;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
    
    ListNode *listNode = new ListNode();
    inputNode(listNode);
    printNode(listNode);

    cout << endl;

    reorderList(listNode);
    printNode(listNode);

    // stack<ListNode*> myStack;
    // ListNode *head = listNode;
    // ListNode *current = head;

    // while(current) {
    //     myStack.push(current);
    //     current = current->next;
    // }

    // current = head;
    // int size = myStack.size();

    // for(int i = 0; i < size/2; i++) {
    //     myStack.top()->next = current->next;
    //     current->next = myStack.top();
    //     current = current->next->next;
    //     myStack.pop();
    // }
    // current->next = NULL;
}   