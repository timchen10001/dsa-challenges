/**
 * @see https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/
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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1, ans = 0;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelNodes(size);

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                levelNodes.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            level++;
            ans += minSwaps(levelNodes);
        }

        return ans;
    }
    int minSwaps(vector<int>& nodes) {
        int n = nodes.size();
        pair<int, int> nodePosition[n];
        for (int i = 0; i < n; i++) {
            nodePosition[i].first = nodes[i];
            nodePosition[i].second = i;
        }

        sort(nodePosition, nodePosition+n);

        vector<bool> visited(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || nodePosition[i].second == i)
                continue;
            
            // find out the number of  node in
            // this cycle and add in ans
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = 1;
                
                j = nodePosition[j].second;
                cycleSize++;
            }

            if (cycleSize > 0) {
                ans += (cycleSize-1);
            }
        }
        return ans;
    }
};