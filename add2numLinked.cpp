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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    //Create a node to save the result and a pointer to print
    ListNode* dummy = new ListNode();
    ListNode* res = dummy;    

    //Store the total of 2 numbers and the carry
    int total = 0;
    int carry = 0;

    //If one node is the end, the other must be added in the result list
    //If all node is at the end, must include the carry that haven't been added to result list
    while(l1 || l2 || carry) {
        
        //Store the carry after one loop if 2 numbers have carry
        total = carry;
        if(l1) {
            total += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            total += l2->val;
            l2 = l2->next;
        }

        //Take the number as E.g : 7 + 8 = 15 -> take 5
        int num = total%10;

        //The carry will be 1
        carry = total/10;

        //Add to the result list int the reverse
        //E.g :
        //Instead of
        // 1234
        //    + 
        //  567
        //It would be
        // 1234
        // +
        // 567
        //Add to the next node as the first node is 0
        dummy->next = new ListNode(num);

        //Move to the next node
        dummy = dummy->next;
    }

    //Ignore the first element of the dummy node
    return res->next;
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif

    // Testing

    ListNode *list1 = new ListNode;
    ListNode *list2 = new ListNode;
    inputNode(list1);    
    inputNode(list2);

    printNode(addTwoNumbers(list1, list2));

    // ListNode *head1 = list1;
    // ListNode *current1 = head1;

    // ListNode *head2 = list2;
    // ListNode *current2 = head2;

    // ListNode* dummy = new ListNode();
    // ListNode* res = dummy;    
    // int total = 0, carry = 0;

    // while(current1 || current2 || carry) {
    //     total = carry;
    //     if(current1) {
    //         total += current1->val;
    //         current1 = current1->next;
    //     }
    //     if(current2) {
    //         total += current2->val;
    //         current2 = current2->next;
    //     }
    //     int num = total%10;
    //     carry = total/10;
    //     dummy->next = new ListNode(num);
    //     dummy = dummy->next;
    // }
    // printNode(res->next);
}   