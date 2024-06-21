#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;
typedef double long db;
typedef string str;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* inputTree() {
   cout << "Enter the value for the root: ";
   int rootValue;
   cin >> rootValue;

   TreeNode *root = new TreeNode(rootValue);
   queue<TreeNode*> q;
   q.push(root);

   while(!q.empty()) {
        TreeNode *current = q.front();
        q.pop();
        
        cout << "Enter the left child of " << current->val << " (or -1 for null): ";
        int leftValue;
        cin >> leftValue;
        
        if(leftValue != -1) {
            current->left = new TreeNode(leftValue);
            q.push(current->left);
        }

        cout << "Enter the right child of " << current->val << " (or -1 for null): ";
        int rightValue;
        cin >> rightValue;

        if(rightValue != -1) {
            current->right = new TreeNode(rightValue);
            q.push(current->right);
        }
    }
    return root;
}

void printTree(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        cout << current->val << " ";

        if(current->left != nullptr) {
            q.push(current->left);
        }

        if(current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

bool isSameTree_1(TreeNode* p, TreeNode* q) {
    
    //This is just sad

    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;
    if(p->val != q->val) return false;

    queue<TreeNode*> queue_tree_1;
    queue<TreeNode*> queue_tree_2;
    queue_tree_1.push(p);
    queue_tree_2.push(q);

    while(!queue_tree_1.empty() && !queue_tree_2.empty()) {
        TreeNode* current_1 = queue_tree_1.front();
        TreeNode* current_2 = queue_tree_2.front();
        queue_tree_1.pop();
        queue_tree_2.pop();
        
        if(current_1->val != current_2->val) return false;

        if(current_1->left != nullptr && current_2->left != nullptr) {
            queue_tree_1.push(current_1->left);
            queue_tree_2.push(current_2->left);
        } 
        else if(current_1->left != nullptr || current_2->left != nullptr) {
            return false;
        }

        if (current_1->right && current_2->right) {
            queue_tree_1.push(current_1->right);
            queue_tree_2.push(current_2->right);
        } 
        else if (current_1->right || current_2->right) {
            return false;
        }
    }
    return queue_tree_1.empty() && queue_tree_2.empty();
}

bool isSameTree_2(TreeNode *p, TreeNode *q) {

    //Base case if both is nullptr -> same structure -> true
    if(p == nullptr && q == nullptr) {
        return true;
    }

    //Base case if only one is nullptr -> different structure -> false
    if(p == nullptr || q == nullptr) {
        return false;
    }

    //Check the value
    if(p->val == q->val) {
        return isSameTree_2(p->left, q->left) && isSameTree_2(p->right, q->right);
    }
}

int main()
{
    TreeNode *p = inputTree();
    TreeNode *q = inputTree();
    if(isSameTree_2(p, q)) cout << "YES";
    else cout << "NO";
}   