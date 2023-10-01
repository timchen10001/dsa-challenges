/**
 * @see https://leetcode.com/problems/validate-binary-search-tree/
 * 
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
    TreeNode* prev;
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
    bool inorder(TreeNode* root) {
        if (root == NULL) return true;
        bool left = inorder(root->left);

        if (!left) return false;
        if (root->left && root->val <= root->left->val) return false;
        if (root->right && root->val >= root->right->val) return false;
        if (prev && prev->val >= root->val) return false;
        prev = root;

        bool right = inorder(root->right);

        return left && right;
    }
};

// inorder + previous node pointer