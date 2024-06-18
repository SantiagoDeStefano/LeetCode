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

TreeNode* invertTree(TreeNode* root) {
    //Eliminate edge cases
    if(root == nullptr) {
        return root;
    }

    //Use queue to access every node, on the left first then second
    queue<TreeNode*> q;
    q.push(root);

    //       4
    //    /     /
    //   2       7
    //  / \     /  /
    // 1   3   6    9
    while(!q.empty()) {
        
        //Access the last node after push -> left node then right node
        TreeNode *current = q.front();
        q.pop();

        //If one node have child and one node doesn't
        if(current->left || current->right) {
            TreeNode *temp = new TreeNode;
            temp = current->left;
            current->left = current->right;
            current->right = temp;
        }

        //Push back the node to access each node's children 
        if(current->left) {
            q.push(current->left);
        }
        if(current->right) {
            q.push(current->right);
        }
    }
    return root;
}

int main()
{
    TreeNode *root = inputTree();
    invertTree(root);
    printTree(root);
}   