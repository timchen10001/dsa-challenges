/**
 * @see https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/
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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        // memo bst val.
        vector<int> inordered;
        inorder(root, inordered);

        int qSize = queries.size();
        vector<vector<int>> answser(qSize);

        for (int i = 0; i < qSize; i++) {
            answser[i] = binarySearch(inordered, queries[i]);
        }

        return answser;
    }
    vector<int> binarySearch(vector<int>& inordered, int target) {
        int n = inordered.size();
        int left = 0, right = n-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = inordered[mid];
            if (target == val) return vector<int>{val, val};
            if (target > val) left = mid+1;
            if (target < val) right = mid-1;
        }
        int min = right >= 0 ? inordered[right] : -1;
        int max = left < n ? inordered[left] : -1;
        return vector<int>{min, max};
    }
    void inorder(TreeNode* root, vector<int>& inordered) {
        if (root == NULL) return;
        inorder(root->left, inordered);
        inordered.push_back(root->val);
        inorder(root->right, inordered);
    }
};