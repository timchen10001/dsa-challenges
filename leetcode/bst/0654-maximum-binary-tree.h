/**
 * @see https://leetcode.com/problems/maximum-binary-tree/description/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int rootIndex = getRootIndex(nums, start, end);
        int rootVal = nums[rootIndex];
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(nums, start, rootIndex-1);
        root->right = buildTree(nums, rootIndex+1, end);
        return root;
    }
    int getRootIndex(vector<int>& nums, int start, int end) {
        int ans = start;
        int n = nums.size();
        int upperBound = end < n ? end : n-1; // check arr right boundary
        for (int i = start; i <= upperBound; i++) {
            if (nums[i] > nums[ans]) ans = i;
        }
        return ans;
    }
};