/**
 * @see https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/submissions/
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
    unordered_map<TreeNode*, pair<int, int>> memo;
    int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {-1, 1};

        if (memo.find(root) != memo.end()) {
            return memo[root];
        }

        int size = 1, sum = root->val;
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        if (left.first != -1) {
            sum += left.first;
            size += left.second;
        }
        if (right.first != -1) {
            sum += right.first;
            size += right.second;
        }

        int avg = sum / size;

        if (avg == root->val) {
            ans++;
        }

        memo[root] = {sum, size};

        return memo[root];
    }
};