/**
 * @see https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int level = 1;

        if (root) q.push(root);

        while (!q.empty()) {
            int size = q.size();

            if (ans.size() != level) ans.push_back(vector<int>{});

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                ans[level-1].push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            level++;
        }
        return ans;
    }
};