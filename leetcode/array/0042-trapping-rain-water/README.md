# 42. Trapping Rain Water

[trapping-rain-water/description](https://leetcode.com/problems/trapping-rain-water/description/)

## Intuition

- We can manipulate the `left` and `right` pointers to approach to the center.
- Memorized the `currentLeftMinH`, and `currentRightMinH` to compare in each iteration.
- In each comparison, once the `currentLeftMinH` is lower than the `height[left]`, it means there is a trap in `left` position, so we can calculate the trap height then update the ans, for the same reason as that for the `right`.
- If the `height[left]` is lower than `height[right]` then we move left to right and vice versa.


## Optimized Solution

```cpp
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0, left = 0, right = n-1;
        int leftMinH = 1, rightMinH = 1;

        // get left start
        while (left < n && height[left] == 0) left++;
        // get right start
        while (right >= 0 && height[right] == 0) right--;

        while (left < right) {
            int currentLeftH = height[left];
            int currentRightH = height[right];

            if (currentLeftH < leftMinH) ans += (leftMinH - currentLeftH);
            if (currentRightH < rightMinH) ans += (rightMinH - currentRightH);
            leftMinH = max(leftMinH, currentLeftH);
            rightMinH = max(rightMinH, currentRightH);

            if (currentLeftH <= currentRightH) left++;
            else right--;
        }

        return ans;
    }
};
```
