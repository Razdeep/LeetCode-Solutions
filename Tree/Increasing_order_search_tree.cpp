// https://leetcode.com/problems/increasing-order-search-tree/
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
    TreeNode* ans;
    
    void inOrder(TreeNode* root) {
        if (root != nullptr) {
            inOrder(root->left);
            TreeNode* cur = ans;
            while (cur != nullptr and cur->right != nullptr) {
                cur = cur->right;
            }
            if (cur == nullptr) {
                ans = cur = new TreeNode();
            } else {
                cur->right = new TreeNode();
                cur = cur->right;
            }
            cur->val = root->val;
            
            inOrder(root->right);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};