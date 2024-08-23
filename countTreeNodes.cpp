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

int countNodes_helper(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    return 1 + countNodes_helper(root->left) + countNodes_helper(root->right);
}

int countNodes(TreeNode* root) {
    return countNodes_helper(root);
}

int main()
{
    TreeNode *root = inputTree();
    printTree(root);
}   