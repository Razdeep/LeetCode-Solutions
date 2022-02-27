// https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;
        
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        
        if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }
        
        for (int root = start; root <= end; ++root) {
            vector<TreeNode*> left_trees = helper(start, root - 1);
            vector<TreeNode*> right_trees = helper(root + 1, end);
            
            for (TreeNode* left_candidate: left_trees) {
                for (TreeNode* right_candidate: right_trees) {
                    auto curr_root_node = new TreeNode(root);
                    curr_root_node->left = left_candidate;
                    curr_root_node->right = right_candidate;
                    res.push_back(curr_root_node);
                }
            }
        }
        
        return res;
    }
};