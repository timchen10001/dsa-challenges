/**
 * @see https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
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
    struct TreeDetails {
        bool isBST;
        int minm;
        int maxm;
        int sum;
        TreeDetails(bool a, int b, int c, int d) {
            isBST = a;
            minm = b;
            maxm = c;
            sum = d;
        }
    };
    TreeDetails* postorder(TreeNode* root, int &ans) {
        if (!root) return new TreeDetails(true, INT_MAX, INT_MIN, 0);
        
        TreeDetails* left = postorder(root->left, ans);
        TreeDetails* right = postorder(root->right, ans);

        bool isBST = left->isBST && right->isBST && root->val > left->maxm && root->val < right->minm;

        int sum = left->sum + right->sum + root->val;

        if (isBST) ans = max(ans, sum);

        int minm = min(root->val, min(left->minm, right->minm));
        int maxm = max(root->val, max(left->maxm, right->maxm));

        return new TreeDetails(isBST, minm, maxm, sum);
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }
};