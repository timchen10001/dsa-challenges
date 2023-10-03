/**
 * @see https://leetcode.com/problems/find-duplicate-subtrees/description/
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> ans;
        stringify(root, mp, ans);
        return ans;
    }
    string stringify(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& ans) {
        if (!root) return "#";

        string nodeStringify = stringify(root->left, mp, ans) + "," + stringify(root->right, mp, ans) + "," + to_string(root->val);

        mp[nodeStringify]++;
        if (mp[nodeStringify] == 2) {
            ans.push_back(root);
        }

        return nodeStringify;
    }
};