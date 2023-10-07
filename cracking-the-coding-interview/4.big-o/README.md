# Big O

> Big O 時間是用來描述演算法效率的語言和度量方法。

## 時間複雜度

這就是漸進執行時間或 Big O 時間概念的含義。

### 最佳情況、最差情況、預期情況

以 `快速排序` 為例子，快速排序會隨機選擇一個元素作為 pivot，然後交換陣列中的值，使小於 pivot 的元素出現在大於 pivot 的元素之前，這做到『部分排序』的效果，然後使用相同的過程遞迴地對左右兩邊進行排序。

- `最佳情況`：
    如果所有元素都相等，快排平均只會遍歷一次，時間複雜度為 `O(N)`。

- `最壞情況`：
    如果取得之 pivot 為陣列最大的元素（很容易發生，舉例來說，選擇了第一個元素為 pivot，然後陣列剛好是依相反的順序排序）。
    在這種情況下，我們的遞迴不會再將陣列切分成左右兩半，然後左邊一個元素，使得時間複雜度退化為 `O(N²)`。

- `預期情況`：
    實際上，這些最佳和最差情況都不會時常發生，所以我們可以期望執行的時間為 `O(N⋅logN)`。

> 大多數演算法的最壞情況和預期情況相同，但有時他們是不同的，碰到這種情況，一定要分別說明這兩種執行時間。

## 空間複雜度

除了時間複雜度，演算法佔用記憶體或空間的資源，也是關注演算法效率的指標之一。

如果我們需要建立一個大小為 n 的陣列，需要 `O(N)`空間，建立一個空間為 nxn 的二維陣列，需要 `O(N²)`空間。

對空間複雜度的討論，較常出現在遞迴呼叫的堆疊空間，例如以下：

```cpp
// Time: O(n)
// Space: O(n)
int sum(int n) {
    if (n <= 0) return 0;
    return n + sum(n-1);
}
```

每次呼叫都會添加一層到 stack 中。

```cpp
sum(4)
    -> sum(3)
        -> sum(2)
            -> sum(1)
                -> sum(0)
```

然而，總數 n 次的呼叫並不代表一定佔用 O(n) 空間，例如以下將 0~n之間的相鄰元素相加求總和：

```cpp
// Time: O(n)
// Space: O(1)
int pairSumSequence(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pairSum(i, i+1);
    }
    return sum;
}

int pairSum(int a, int b) {
    return a + b;
}
```

## 去掉常數

對於特定的輸入，`O(N)` 很可能會比 `O(1)` 程式碼執行的還要快，BigO 表示的只是`增長率`，因此我們可以刪除執行時間裡的常數，一個被描述為 `O(2N)` 的演算法實際上是 `O(N)`。

```cpp
// Time: O(2N)
// Space: O(1)
int min = INT_MAX;
int max = INT_MIN;
for(int x: arr) {
    if (x < min) min = x;
    if (x > max) max = x;
}
```

```cpp
// Time: O(N + N)
// Space: O(1)
int min = INT_MAX;
int max = INT_MIN;
for(int x: arr) {
    if (x < min) min = x;
}
for(int x: arr) {
    if (x > max) max = x;
}
```

## 去掉非優勢項

如何處理 `O(N² + N)` 這樣的運算式？，第二個 N 並不是可以被去掉的常數，但他又不是左右執行時間增長率的主要元兇。

`O(X!)` > `O(2ˣ)` > `O(X²)` > `O(X⋅logX)` > `O(X)` > `O(logX)`

## 加與乘

- 相加

```cpp
// Time: O(A + B)
// Space: O(1)
for(int a: arrA) {
    print(a)
}
for(int b: arrB) {
    print(b)
}
```

- 相乘

```cpp
// Time: O(A⋅B)
// Space: O(1)
for (int a: arrA) {
    for (int b: arrB) {
        print(a + "," + b);
    }
}
```

## 平攤時間 (Amortized Time)

平攤時間允許我們描述以下狀況：

> 最壞的情況每隔一段時間就會發生，但他一但發生了，在很長時間內不會再發生，以至於代價可以`被平攤`。

以 c++ 為例子，插入一個元素至 vector (動態陣列)，`在陣列達到容量上限 N 時`，將建立一個容量加倍 `2N` 的新陣列，進行搬家，此時操作的時間複雜度 `O(N)` 就會與尚未到達容量前的 `O(1)` 不同，由於不會經常發生，絕大多數插入都在 O(1) 時間內，但是我們需要一個兼顧時間的概念，這就是平攤時間。

實際上的計算方式大概如下：

我們插入元素時，當陣列的大小等於 `2ˣ` 時，容量就要加倍，所以假設有一系列元素被插入時，我們在陣列大小為 1, 2, 4, 8, 16, ..., X 進行陣列容量翻倍，而翻倍時分別需要做 1, 2, 4, 8, 16, ..., X 次的複製。

1 + 2 + 4 + 8 + 16 + ... + X ≈
X + X/2 + X/4 + X/8 + ... + 1 ≈
X⋅2 = `2X`

![幾何級數](https://wikimedia.org/api/rest_v1/media/math/render/svg/9996f0972a662a0caac34be3da846c8b4dbb16f4)

因此，X次插入需要 `O(2X)`，每次插入的 Amortized Time 為 `O(1)`。

## logN 執行時間

當看到一個問題時，問題空間中的元素數量每次都減半，那麼執行時間又很可能為 O(logN)。

以二元搜尋法為例子：

```cpp
// Time: O(logN)
// Space: O(1)
int binarySearch(vector<int>& arr, int target) {
    int n = arr.size();
    int left = 0, right = n-1;

    while (left <= right) {
        int mid = left + (right-left)/2;
        if (arr[mid] == target) return mid;
        if (target < arr[mid]) right = mid-1; // 右邊減半
        if (target > arr[mid]) left = mid+1; // 左邊減半
    }

    return -1;
}
```

```text
search 9 within {1, 5, 8, 9, 11, 13, 15, 19, 20}
    compare 9 to 11 -> smaller,
    search 9 within {1, 5, 8, 9}
        compare 9 to 8 -> bigger,
        search 9 withing {9}
            compare 9 to 9 -> equal,
            return
```

## 遞迴 執行時間

- 時間複雜度通常是 `O(分支^深度)` 分支 取決於每一次 遞迴 呼叫分支的次數

- 空間複雜度為 `O(深度)`

```cpp
// Time: O(2ᴺ)
// Space: O(N)
int f(int n) {
    if (n <= 1) return 1;
    return fib(n-1) + fig(n-1)
}
```

```text
                                f(4)
                f(3)                            f(3)
        f(2)            f(2)            f(2)            f(2)
    f(1)    f(1)    f(1)    f(1)    f(1)    f(1)    f(1)    f(1)
```

## 範例練習

### 範例 1

> Time: O(N) and Space: O(1)

### 範例 2

> Time: O(N²) and Space: O(1)

### 範例 3

> Time: O(N²) and Space: O(1)

### 範例 4

> Time: O(A⋅B) and Space: O(1)

### 範例 5

> Time: O(A⋅B) and Space: O(1)

### 範例 6

> Time: O(N) and Space: O(1)

### 範例 7

> O(N+P), O(2N), O(N + logN)

### 範例 8

> - 定義 S 為最長字串長度，A 為陣列長度。
> - 對每個字串排序是 O(SlogS)
> - 須對陣列中每個字串都這樣做，故為 O(A * SlogS)
> - 排序 A 個字串，每一個字串比較需要 O(S)，總共要比較 O(AlogA) 次，這將花費 O(S * AlogA) 的時間。
> - 加總 O(A*SlogS + S*AlogA) = `O(A*S*(logA + logS))`

### 範例 9

> - 假設平衡二元樹總共有 N 的節點 (高度 logN)
> - 每次遞迴呼叫兩個分支，並加總，加總為 O(1)，呼叫兩個分支為 O(2^(logN) + 2^(logN))
> - O(2^(logN) + 1 + 2^(logN)) = O(2^logN)
> O(2^logN) = `O(N)`
