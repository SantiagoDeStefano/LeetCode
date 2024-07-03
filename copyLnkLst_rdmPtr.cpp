#include<iostream>
#include<unordered_map>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//This take way longer than it should
Node* copyRandomList(Node* head) {
    Node *current = head;

    //A map to copy the list
    unordered_map<Node*, Node*> copied;
    
    //First pass - create a node with just value
    while(current != nullptr) {
        copied[current] = new Node(current->val);
        current = current->next;
    }    

    //Reset the pointer 
    current = head;

    //Second pass - link the node with next and random pointer
    while(current != nullptr) {
        copied[current]->next = copied[current->next];
        copied[current]->random = copied[current->random];
        current = current->next;
    }
    
    return copied[head];
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
}   