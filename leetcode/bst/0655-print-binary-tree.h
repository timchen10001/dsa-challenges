/**
 * @see https://leetcode.com/problems/print-binary-tree/description/
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
    int height;
    vector<vector<string>> printTree(TreeNode* root) {
        height = findHeight(root);
        int m = height+1, n = pow(2, height+1)-1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        int r = 0;
        int c = (n-1)/2;
        print(root, ans, r, c);
        return ans;
        
    }
    void print(TreeNode* root, vector<vector<string>>& ans, int r, int c) {
        if (!root) return;
        ans[r][c] = to_string(root->val);
        print(root->left, ans, r+1, c-pow(2, height-r-1));
        print(root->right, ans, r+1, c+pow(2, height-r-1));
    }
    int findHeight(TreeNode* root) {
        if (!root) return -1;
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        return 1 + max(left, right);
    }
};