# [Example 12] Permutation

```c++
void permutation(string str) {
    resolve(str, "");
}

void resolve(string str, string prefix) {
    if (str.size() == 0) {
        printf(prefix); // O(N)
    } else {
        for (int i = 0; i < str.size(); i++) {
            string rem = str.substr(0, i) + str.substr(i+1); // O(N)
            resolve(rem, prefix + str[i]); 
        }
    }
}
```

## Answer

1. 每次函式被呼叫需要花多少時間?
    > 每個節點 `O(N)`

2. 函式會被呼叫多少次?
   > 葉節點會有 `N!` 個
   > 最差情況堆疊樹節點大概有 `N*N!` (非精準預估)
   > 根據泰勒展開式知道，節點數必定會小於 `e*N!` 個 e ≈ 2.718

根據非精確節點預估，permutation算法時間複雜度為 O(N*N*N!)，等價於 `O((N+2)!)`

根據泰勒展開式精準估計，答案為 O(N * e * N!)
去掉 e 常數 => O(N*N!)，等價於 `O((N+1)!)`

