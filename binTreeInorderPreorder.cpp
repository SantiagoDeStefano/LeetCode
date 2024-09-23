#include<iostream>
#include<queue>
#include<deque>
#include<algorithm>
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

TreeNode* buildTree_helper(deque<int>& preorder, vector<int>& inorder) {
    if(!inorder.empty()) {
        int value = preorder.front();
        preorder.pop_front();
        auto it = find(inorder.begin(), inorder.end(), value);
        int index = it - inorder.begin();

        TreeNode *root = new TreeNode(value);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        root->left = buildTree_helper(preorder, leftInorder);
        root->right = buildTree_helper(preorder, rightInorder);

        return root;
    }
    return nullptr;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    deque<int> preorder_deque(preorder.begin(), preorder.end());
    return buildTree_helper(preorder_deque, inorder);
}

int main()
{
    TreeNode *root = new TreeNode;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    root = buildTree(preorder, inorder);
    printTree(root);
}   