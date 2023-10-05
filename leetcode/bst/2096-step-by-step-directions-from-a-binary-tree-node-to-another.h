/**
 * @see https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> depth;
    TreeNode *startNode = nullptr, *destNode = nullptr;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        dfs(root, startValue, destValue, 1);

        string ans = "";
        TreeNode *lca = LCA(startNode, destNode);
        TreeNode *start = startNode, *dest = destNode; 

        while (dest != lca) {
            if (parent[dest]->left == dest) {
                ans.push_back('L');
            }
            if (parent[dest]->right == dest) {
                ans.push_back('R');
            }
            dest = parent[dest];
        }

        while (start != lca) {
            start = parent[start];
            ans.push_back('U');
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
    TreeNode* LCA(TreeNode *u, TreeNode *v) {
        int du = depth[u], dv = depth[v];

        if (du != dv) {
            if (du > dv) {
                for (int i = 0; i < du-dv; i++) {
                    u = parent[u] ? parent[u] : u;
                }
            } else {
                for (int i = 0; i < dv-du; i++) {
                    v = parent[v] ? parent[v] : v;
                }
            }
        }

        while (u != v) {
            u = parent[u] ? parent[u] : u;
            v = parent[v] ? parent[v] : v;
        }

        return u; // or v
    }
    void dfs(TreeNode* root, int startValue, int destValue, int deep) {
        if (!root) return;

        if (root->val == startValue)
            startNode = root;
        if (root->val == destValue)
            destNode = root;

        if (startNode && destNode) return;

        if (root->left) {
            parent[root->left] = root;
            depth[root->left] = deep+1;
        }
        if (root->right) {
            parent[root->right] = root;
            depth[root->right] = deep+1;
        }

        dfs(root->left, startValue, destValue, deep+1);
        dfs(root->right, startValue, destValue, deep+1);
    }
};