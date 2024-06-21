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

//Check if the two tree is the same or not
bool check_isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root == nullptr && subRoot == nullptr) {
        return true;
    }
    if(root == nullptr || subRoot == nullptr) {
        return false;
    }
    if(root->val == subRoot->val) {
        return check_isSubtree(root->left, subRoot->left) && check_isSubtree(root->right, subRoot->right);
    }
    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    
    //If root == nullptr and subRoot != nullptr -> no subRoot in root
    //If root != nullptr and subRoot == nullptr -> subRoot is not in root
    if(root == nullptr || subRoot == nullptr) {
        return false;
    }
    if(check_isSubtree(root, subRoot)) {
        return true;
    }

    //Check if subRoot is a subtree of the left or right child of the current node
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    TreeNode *root = inputTree();
    TreeNode *subRoot = inputTree();

    if(isSubtree(root, subRoot)) cout << "YES";
    else cout << "NO";
}   