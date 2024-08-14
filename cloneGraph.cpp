#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph_helper(Node* curr, unordered_map<Node*, Node*>& map) {
    vector<Node*> neighbour;
    Node* clone = new Node(curr->val);
    map[curr] = clone;
    for(auto it:curr->neighbors) {
        if(map.find(it) != map.end()) {
            neighbour.push_back(map[it]);
        }
        else {
            neighbour.push_back(cloneGraph_helper(it, map));
        }
    }
    clone->neighbors = neighbour;
    return clone;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> map;
    if(node == nullptr) {
        return NULL;
    }
    if(node->neighbors.size() == 0) {
        Node* clone = new Node(node->val);
        return clone;
    }
    return cloneGraph_helper(node, map);
}

int main()
{
ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 #ifndef ONLINE_JUDGE
   freopen("main.inp", "r", stdin);
   freopen("main.out", "w", stdout);
#endif
}