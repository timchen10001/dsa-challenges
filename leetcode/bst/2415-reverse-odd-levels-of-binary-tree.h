/**
 * @see https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            if (level % 2 == 1) {
                vector<int> levelNums(size);
                vector<TreeNode*> levelNodes(size);

                for (int i = 0; i < size; i++) {
                    TreeNode* curr = q.front();
                    q.pop();

                    levelNodes[i] = curr;
                    levelNums[i] = curr->val;

                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
                reverse(levelNums.begin(), levelNums.end());

                for (int i = 0; i < size; i++) {
                    TreeNode* curr = levelNodes[i];
                    curr->val = levelNums[i];
                }
            } else {
                for (int i = 0; i < size; i++) {
                    TreeNode* curr = q.front();
                    q.pop();
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
            }
            level++;
        }
        return root;
    }
};