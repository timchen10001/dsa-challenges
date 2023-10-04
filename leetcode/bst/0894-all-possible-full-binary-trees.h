/**
 * @see https://leetcode.com/problems/all-possible-full-binary-trees/description/
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
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        vector<TreeNode*> ans;

        if (n == 1) {
            TreeNode* temp = new TreeNode(0);
            ans.push_back(temp);
            return ans;
        }

        if (n % 2) {
            for (int i = 0; i < n; i++) {
                int left = i, right = n - i - 1;
                vector<TreeNode*> l = allPossibleFBT(left);
                vector<TreeNode*> r = allPossibleFBT(right);
                for (auto& x: l) {
                    for (auto& y: r) {
                        TreeNode* temp = new TreeNode(0);
                        temp->left = x;
                        temp->right = y;
                        ans.push_back(temp);
                    }
                }
            }
            memo[n] = ans;
        }

        return ans;
    }
};