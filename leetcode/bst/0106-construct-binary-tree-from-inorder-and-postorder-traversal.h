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
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMp;
        for (int i = 0; i < inorder.size(); i++) {
            inMp[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMp);
    }
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inMp) {
        if (inStart > inEnd || postStart > postEnd) return NULL;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int inRoot = inMp[rootVal];
        int leftNums = inRoot - inStart;
        root->left = buildTreeHelper(inorder, inStart, inRoot-1, postorder, postStart, postStart+leftNums-1, inMp);
        root->right = buildTreeHelper(inorder, inRoot+1, inEnd, postorder, postStart+leftNums, postEnd-1, inMp);
        return root;
    }
};