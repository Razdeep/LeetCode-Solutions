// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return vector<int>();
        
        vector<int> res;
        res.push_back(root->val);
        
        for (auto child: root->children) {
            auto grand_children = preorder(child);
            for (auto grand_child: grand_children) {
                res.push_back(grand_child);
            }
        }
        
        return res;
    }
};