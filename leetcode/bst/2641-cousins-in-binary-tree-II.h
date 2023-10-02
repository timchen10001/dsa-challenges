/**
 * @see https://leetcode.com/problems/cousins-in-binary-tree-ii/description/
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> levelSum;
        queue<pair<TreeNode*, int>> q;
        int depth = 1;

        levelSum[depth] = root->val;
        q.push(make_pair(root, root->val));

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<TreeNode*, int> p = q.front();
                q.pop();

                TreeNode* curr = p.first;
                int currentSiblingVal = p.second;
                int leftVal = curr->left ? curr->left->val : 0;
                int rightVal = curr->right ? curr->right->val : 0;
                int nextSiblingVal = leftVal + rightVal;

                curr->val = levelSum[depth] - currentSiblingVal;
                
                if (curr->left) {
                    levelSum[depth+1] += curr->left->val;
                    q.push(make_pair(curr->left, nextSiblingVal));
                }
                if (curr->right) {
                    levelSum[depth+1] += curr->right->val;
                    q.push(make_pair(curr->right, nextSiblingVal));
                }
            }
            depth++;
        }

        return root;
    }
};