#include<iostream>
#include<queue>
#include<set>
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

void pathSum_helper(TreeNode* root, int targetSum, int currSum, vector<int>& subSum, vector<vector<int>>& result) {
    if(root == nullptr) {
        return;
    }
    currSum = currSum + root->val;
    subSum.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr && currSum == targetSum) {
        result.push_back(subSum);
    }
    else {
        pathSum_helper(root->left, targetSum, currSum, subSum, result);
        pathSum_helper(root->right, targetSum, currSum, subSum, result);
    }
    subSum.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> subSum;
    vector<vector<int>> result;
    pathSum_helper(root, targetSum, 0, subSum, result);
    return result;
}

int main()
{   
    TreeNode *root = inputTree();
    printTree(root);
}   