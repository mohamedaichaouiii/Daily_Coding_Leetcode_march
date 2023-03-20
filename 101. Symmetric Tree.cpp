/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
        return true;//base case
    }
    return isSymmetric(root->left, root->right);
        
    }
    bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
    if (leftNode == nullptr && rightNode == nullptr) {
        return true;
    }
    if (leftNode == nullptr || rightNode == nullptr) {
        return false;
    }
    if (leftNode->val != rightNode->val) {
        return false;
    }
    return isSymmetric(leftNode->left, rightNode->right) && isSymmetric(leftNode->right, rightNode->left);
}
};