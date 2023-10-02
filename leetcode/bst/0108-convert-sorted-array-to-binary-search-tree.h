/**
 * @see https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1); 
    }
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;
        int rootVal = nums[mid];

        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(nums, left, mid-1);
        root->right = buildTree(nums, mid+1, right);
        return root;
    }
};