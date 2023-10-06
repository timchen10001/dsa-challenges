/**
 * @see https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/
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
    long long prev = LLONG_MIN;
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, int> nodes;

        for (auto& tree: trees) {
            nodes[tree->val]++;
            if (tree->left) nodes[tree->left->val]++;
            if (tree->right) nodes[tree->right->val]++;
        }

        TreeNode* curr = NULL;
        for (auto& tree: trees) {
            // if a root node val is not equals to leaf of any other root
            // then if can be the root node of combined tree.
            if (nodes[tree->val] == 1) {
                if (curr) return NULL;
                curr = tree;
            }
        }

        unordered_map<int, TreeNode*> mp;
        for (auto& tree: trees) {
            mp[tree->val] = tree;
        }
        
        // call core function
        makeTree(curr, mp);

        int count = 0;
        for (auto& kv: mp) {
            if (kv.second) count++;
        }

        if (count > 1) return NULL;
        if (isValidBST(curr)) return curr;
        return NULL;
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (root->val <= prev) return false;
        prev = root->val;
        return isValidBST(root->right);
    }
    void makeTree(TreeNode* &root, unordered_map<int, TreeNode*>& mp) {
        if (!root) return;

        if (root->left && mp[root->left->val]) {
            root->left = mp[root->left->val];
            mp[root->left->val] = NULL;
        }
        if (root->right && mp[root->right->val]) {
            root->right = mp[root->right->val];
            mp[root->right->val] = NULL;
        }
        makeTree(root->left, mp);
        makeTree(root->right, mp);
    }
};