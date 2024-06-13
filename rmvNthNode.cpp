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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    //Create a new result to store the removed list to handling edge case
    //When removing the 1st node or very small test cases (when head only contains 1 or 2 elements)
    ListNode *result = new ListNode(0, head);

    //Use a pointer starting from the second element of ListNode *result -> handling edge cases
    ListNode *current = result;

    //Shouldn't use (head.size - n), avoiding undesired result

    // 1 -> 2 -> 3 -> 4 -> 5
    //Move the head to the (head.size - n - 1)th element
    // 1 -> 2 -> 3 -> 4 -> 5
    //           h     
    for(int i = 0; i < n; i++) {
        head = head->next;
    }

    //As the head moved to the last element, the current pointer will be in the exact
    //Position the head were before the loop
    //-> 2 pointers (one fast, one slow)
    // 1 -> 2 -> 3 -> 4 -> 5
    //           c         h   
    while(head) {
        head = head->next;
        current = current->next;
    }

    //Replace the element
    current->next = current->next->next;

    //Return the result starting from second element
    //This will eliminate edge case
    //E.g: 1, remove 1st element from the end of the list
    //Result would be NULL (Nothing)
    return result->next;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    //Testing

    // int n;
    // cin >> n;

    ListNode *list = new ListNode;
    inputNode(list);

    printNode(removeNthFromEnd(list, 1));

    // printNode(list);
    // ListNode *head = list;

    // //Ignore above

    // ListNode *current = head;
    // int size = 0;

    // while(current) {
    //     size = size + 1;
    //     current = current->next;
    // }

    // current = head;
    // int index = 1;

    // while(current) {
    //     if(index == size - n) {
    //         current->next = current->next->next;
    //         break;
    //     }
    //     else {
    //         index = index + 1;
    //         current = current->next;
    //     }
    // }

    // printNode(head);
}   