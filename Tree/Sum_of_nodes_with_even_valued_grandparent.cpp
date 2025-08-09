// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent

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
    int solve(TreeNode* cur, TreeNode* parent, TreeNode* grand_parent) {
        int ans = 0;

        if (cur == nullptr) {
            return ans;
        }

        if (grand_parent->val % 2 == 0) {
            ans += cur->val;
        }

        int ans_left = solve(cur->left, cur, parent);
        int ans_right = solve(cur->right, cur, parent);

        return ans + ans_left + ans_right;
    }

    int sumEvenGrandparent(TreeNode* root) {
        int left_ans = 0;
        int right_ans = 0;
        if (root->left != nullptr) {
            left_ans = solve(root->left->left, root->left, root)
                        + solve(root->left->right, root->left, root);
        }
        if (root->right != nullptr) {
            right_ans = solve(root->right->left, root->right, root) 
                    + solve(root->right->right, root->right, root);
        }
        return left_ans + right_ans;
    }
};