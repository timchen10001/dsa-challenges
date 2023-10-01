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
 * @see https://leetcode.com/problems/symmetric-tree/description/
 */

// recursive method
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val && isMirror(left->right, right->left) && isMirror(left->left, right->right);
    }
};

// iterative method
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while(!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();

            if (left == NULL && right == NULL) {
                continue;
            }

            if (left == NULL || right == NULL) {
                return false;
            }
            
            if (left->val != right->val) {
                return false;
            }

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};