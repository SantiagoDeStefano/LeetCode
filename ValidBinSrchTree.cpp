#include<iostream>
#include<queue>
#include <limits>
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

bool isValidBST_(TreeNode* root, long long left, long long right) {
    if(root == nullptr) {
        return true;
    }

        //       8
        //     /   \
        //    3     10
        //   / \      \
        //  1   6      14
        //     / \     /
        //    4   7   13

        //Current node's value must fall between left and right
    if(root->val >= right || root->val <= left) {
        return false;
    } 

    //Update the range
    //Left:              left             < val < right(updated with root->val)
    //Right: left(updated with root->val) < val < right
    return isValidBST_(root->left, left, root->val) && isValidBST_(root->right, root->val, right);
}

bool isValidBST(TreeNode* root) {
    long long int min = -1000000000000, max = 1000000000000;
    return isValidBST_(root, min, max);
}

int main()
{
    TreeNode *root = inputTree();
    if(isValidBST(root)) cout << "YES";
    else cout << "NO";
}   