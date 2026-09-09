/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return build(nodes, 0, nodes.size() - 1);
    }

private:
    void inorder(TreeNode* node, vector<TreeNode*>& nodes) {
        if (!node)
            return;
        inorder(node->left, nodes);
        nodes.push_back(node);
        inorder(node->right, nodes);
    }

    TreeNode* build(vector<TreeNode*>& nodes, int lo, int hi) {
        if (lo > hi)
            return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = nodes[mid];
        node->left = build(nodes, lo, mid - 1);
        node->right = build(nodes, mid + 1, hi);
        return node;
    }
};