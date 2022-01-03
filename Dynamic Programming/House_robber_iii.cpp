// https://leetcode.com/problems/house-robber-iii/

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
    map<TreeNode*, int> cache;
public:
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        auto cache_ptr = cache.find(root);
        if (cache_ptr != cache.end()) {
            return cache_ptr->second;
        }
        
        int without_current_node = 0;
        if (root->left != nullptr) {
            without_current_node += helper(root->left);
        }
        if (root->right != nullptr) {
            without_current_node += helper(root->right);
        }
        
        int with_current_node = root->val;
        
        if (root->left != nullptr) {
            if (root->left->left != nullptr) {
                with_current_node += helper(root->left->left);
            }
            if (root->left->right != nullptr) {
                with_current_node += helper(root->left->right);
            }
        }
                                        
        if (root->right != nullptr) {
            if (root->right->left != nullptr) {
                with_current_node += helper(root->right->left);
            }
            if (root->right->right != nullptr) {
                with_current_node += helper(root->right->right);
            }
        }
                                        
        return cache[root] = max(without_current_node, with_current_node);
    }
    
    int rob(TreeNode* root) {
        return helper(root);
    }
};