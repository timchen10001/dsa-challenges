/**
 * @see https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
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
class Solution1BFS {
public:
    unordered_map<int, set<TreeNode*>> connected;
    int amountOfTime(TreeNode* root, int start) {
        int minutes = 0;
        queue<TreeNode*> q;
        TreeNode* startNode = getStartNode(root, start);
        set<TreeNode*> infected;

        if (startNode) q.push(startNode);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                infected.insert(curr);
                set<TreeNode*>& connections = connected[curr->val];

                for (auto& c: connections) {
                    if (!infected.count(c)) {
                        q.push(c);
                    }
                }
            }
            minutes++;
        }

        return minutes-1;
    }
    TreeNode* getStartNode(TreeNode* root, int start) {
        TreeNode* startNode = nullptr;
        queue<TreeNode*> q;

        if (root) {
            q.push(root);
            connected[root->val] = set<TreeNode*>{};
        }
        

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start) {
                startNode = curr;
            }

            if (curr->left) {
                q.push(curr->left);
                connected[curr->val].insert(curr->left);

                if (connected.find(curr->left->val) == connected.end())
                    connected[curr->left->val] = set<TreeNode*>{};
                connected[curr->left->val].insert(curr);
            }
            if (curr->right) {
                q.push(curr->right);
                connected[curr->val].insert(curr->right);

                if (connected.find(curr->right->val) == connected.end())
                    connected[curr->right->val] = set<TreeNode*>{};
                connected[curr->right->val].insert(curr);
            }
        }
        return startNode;
    }
};

// Faster and more efficiency in space.
class SolutionDFS {
public:
    int ans = 0;
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return ans;
    }
    pair<bool, int> dfs(TreeNode* root, int start) {
        if (!root) return {false,0};

        pair<bool, int> left = dfs(root->left, start);
        pair<bool, int> right = dfs(root->right, start);

        // find the start-node (as root)
        if (root->val == start) {
            int temp = max(left.second, right.second);
            ans = max(ans, temp);
            return {true, 0};
        }
        // parent node is start-node
        if (left.first) {
            int sum = left.second+right.second + 1;
            ans = max(ans, sum);
            return {true, left.second+1};
        }
        if (right.first) {
            int sum = left.second+right.second + 1;
            ans = max(ans, sum);
            return {true, right.second+1};
        }
        int sum = max(left.second, right.second);
        return {false, sum+1};
    }
};