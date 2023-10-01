/**
 * @see https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree
 * 
 * Complexity
 * Time O(n)
 * Space O(1)
 */
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n-1; i; i -= 2) {
            int right = cost[i], left = cost[i-1];
            ans += abs(right - left);
            // cost[(i-1) >> 1] += max(left, right); //or
            cost[(i-1) / 2] += max(left, right);
            // (i - 1) / 2 == (i-1) >> 1 (Get parent node index)
        }
        return ans;
    }
};
