/**
 * @see https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMp;
        for (int i = 0; i < inorder.size(); i++) {
            inMp[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMp);
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMp) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int inRoot = inMp[rootVal];
        int leftNums = inRoot - inStart;

        root->left = buildTreeHelper(preorder, preStart+1, preStart+leftNums, inorder, inStart, inRoot-1, inMp);
        root->right = buildTreeHelper(preorder, preStart+leftNums+1, preEnd, inorder, inRoot+1, inEnd, inMp);
    
        return root;
    }
};