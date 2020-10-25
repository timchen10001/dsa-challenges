## temp -> 暫存基準點的值
## j 為 i 為基準時，往左邊迭代檢查之index
## 每次迭代發生 : 左邊有沒有比右邊大的，有的話 右邊值 換成左邊值，因為一開始有暫存點，所以到了 左邊比右邊小時，右邊值換成暫存值 temp


## l -> left, r -> right
##     l r
## 1.  5 4 3 2 1 0   temp==4
##     j i
##                   arr[j] > temp == true && j>0;
## ->
##   l r
##     5 5 3 2 1 0   j < 0, break;
##   j   i
## ->                 arr[j+1] = temp
##     4 5 3 2 1 0
## i = 1 迭代完成


##       l r
## 2.  4 5 3 2 1 0   5 > temp==3 -> arr[j+1] = arr[j]
##       j i
##     l r
##     4 5 5 2 1 0   4 > temp==3 -> arr[j+1] = arr[j]
##     j   i
##   l r
##     4 4 5 2 1 0   j<0 -> break;
##   j     i
##     3 4 5 2 1 0   arr[j+1] = temp;
##     以此類推