# Run main.cpp
```bsah
chmod -x ./run.sh && ./run.sh
```


# terminal result
```cpp
---Push method---

推入: 57
[ 0,  ]

推入: 86
[ 0, 57,  ]

推入: 23
[ 0, 57, 86,  ]

推入: 60
[ 0, 57, 86, 23,  ]

推入: 12
[ 0, 57, 86, 23, 60,  ]

推入: 47
[ 0, 57, 86, 23, 60, 12,  ]

---Pop method---

移出: 12
[ 0, 57, 86, 23, 60 ]

移出: 60
[ 0, 57, 86, 23 ]

移出: 23
[ 0, 57, 86 ]

移出: 86
[ 0, 57 ]

移出: 57
[ 0 ]

將上面Pop值重新推入堆中 ...

---Insert method---

目前堆疊狀態
[ 0, 57, 86, 23, 60, 12,  ]

在引索 5 插入亂數 28
[ 0, 57, 86, 23, 60, 28, 12,  ]

在引索 4 插入亂數 89
[ 0, 57, 86, 23, 89, 60, 28, 12,  ]

在引索 12 插入亂數 71
[ 0, 57, 86, 23, 89, 60, 28, 12, 47,  ]

在引索 11 插入亂數 51
[ 0, 57, 86, 23, 89, 60, 28, 12, 47, 71,  ]

在引索 11 插入亂數 7
[ 0, 57, 86, 23, 89, 60, 28, 12, 47, 71, 51,  ]

---Remove method---

目前堆疊狀態
[ 0, 57, 86, 23, 89, 60, 28, 12, 47, 71, 51,  ]

刪除引索 4 的 89
[ 0, 57, 86, 23, 60, 28, 12, 47, 71, 51,  ]

刪除引索 4 的 60
[ 0, 57, 86, 23, 28, 12, 47, 71, 51,  ]

刪除引索 6 的 47
[ 0, 57, 86, 23, 28, 12, 71, 51,  ]

刪除引索 6 的 71
[ 0, 57, 86, 23, 28, 12, 51,  ]

刪除引索 5 的 12
[ 0, 57, 86, 23, 28, 51,  ]

刪除引索 1 的 57
[ 0, 86, 23, 28, 51,  ]

刪除引索 4 的 51
[ 0, 86, 23, 28,  ]

刪除引索 3 的 28
[ 0, 86, 23,  ]

刪除引索 2 的 23
[ 0, 86,  ]

刪除引索 1 的 86
[ 0,  ]

刪除引索 0 的 0
[  ]
After Inserting 1000 in position 0
[ 1000,  ]
After Clearing:
[  ]
```