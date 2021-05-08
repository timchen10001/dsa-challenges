# Run main.cpp
```bash
chmod +x ./run.sh && ./run.sh
```

# terminal result
```cpp
Input Edges:
9
1 1 2 2 3 4 4 5 5
2 6 3 7 4 5 7 6 7
25 5 12 10 8 16 14 20 18

testing adj:
 1 1 2 2 3 4 4 5 5
 2 6 3 7 4 5 7 6 7
 25 5 12 10 8 16 14 20 18

testing set:
 -1 -1 -1 -1 -1 -1 -1 -1
testing included:
 0 0 0 0 0 0 0 0 0
testing time:
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0


after unite

testing adj:
 1 1 2 2 3 4 4 5 5
 2 6 3 7 4 5 7 6 7
 25 5 12 10 8 16 14 20 18

testing set:
 -1 6 7 4 -7 4 4 4
testing included:
 0 1 1 1 1 1 1 1 1
testing time:
 1 3 2 2 4 5 0
 6 4 7 3 5 6 0
```
