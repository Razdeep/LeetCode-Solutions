// https://leetcode.com/contest/weekly-contest-311/problems/reverse-odd-levels-of-binary-tree/

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
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        
        vector<int> tmp;
        queue<TreeNode*> q2, q3;
        
        while (!q.empty()) {
            q3 = q;
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left) {
                    q2.push(cur->left);
                    tmp.push_back(cur->left->val);
                }
                
                if (cur->right) {
                    q2.push(cur->right);
                    tmp.push_back(cur->right->val);
                }
                
            }
            
            if (level % 2 == 0) {
                while (!q3.empty()) {
                    TreeNode* cur = q3.front();
                    q3.pop();

                    if (cur->left) {
                        cur->left->val = tmp.back();
                        tmp.pop_back();
                    }

                    if (cur->right) {
                        cur->right->val = tmp.back();
                        tmp.pop_back();
                    }
                }
            }
            ++level;
            swap(q, q2);
        }
        
        return root;
    }
};