# 11. Container With Most Water

[container-with-most-water](https://leetcode.com/problems/container-with-most-water/)

## Intuition

Find the maximum product of width and height

## Brute Force Solution

```cpp
// Time: O(N²)
// Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for (int i = 0; i < height.size()-1; i++) {
            for (int j = i+1; j < height.size(); j++) {
                int w = j - i;
                int h = min(height[i], height[j]);
                ans = max(ans, w*h);
            }
        }
        return ans;
    }
};
```

## Optimized Solution

> Greedy method + two pointers

```cpp
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, left = 0, right = height.size()-1;

        while (left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = w*h;
            ans = max(ans, area);

            // 如果當下左邊比右邊低，那左邊就往內縮，反之亦然。
            if (height[left] <= height[right]) left++;
            else right--;
        }

        return ans;
    }
};
```
