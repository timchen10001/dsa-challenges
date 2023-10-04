/**
 * @see https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        unordered_map<int, vector<int>> mp;
        set<int> cols;
        int level = 0;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            int size = q.size();

            unordered_map<int, vector<int>> levelMp;
            set<int> levelCols;

            for (int i = 0; i < size; i++) {
                pair<TreeNode*, pair<int, int>> p = q.front();
                q.pop();

                TreeNode* curr = p.first;
                int row = p.second.first, col = p.second.second;

                if (!levelMp.count(col)) levelMp[col] = vector<int>{};
                levelMp[col].emplace_back(curr->val);
                levelCols.insert(col);

                if (curr->left) q.push({curr->left, {row+1, col-1}});
                if (curr->right) q.push({curr->right, {row+1, col+1}});
            }

            for (auto& levelCol: levelCols) {
                cols.insert(levelCol);
                sort(levelMp[levelCol].begin(), levelMp[levelCol].end());

                for (auto& v: levelMp[levelCol]) {
                    mp[levelCol].emplace_back(v);
                }
            }

            level++;
        }

        for (auto& col: cols) {
            ans.emplace_back(mp[col]);
        }

        return ans;
    }
};