
# Insertion Sort
## 想像正在排序撲克牌
## 將第i張紙牌加入「前i−1張排序過」的紙牌組合，得到i張排序過的紙牌組合。

```
origin array: 

[ 70, 30, 40, 10, 80, 20, 90, 100, 75, 60, 45 ]

sorted array: 

[ 10, 20, 30, 40, 45, 60, 70, 75, 80, 90, 100 ]

temp -> 暫存基準點的值

j 為 i 為基準時，往左邊迭代檢查之index.

每次迭代發生 : 左邊有沒有比右邊大的，有的話 右邊值 換成左邊值，因為一開始有暫存點，所以到了 左邊比右邊小時，右邊值換成暫存值 temp

 l -> left, r -> right
     l r
 1.  5 4 3 2 1 0   temp==4
     j i
                   arr[j] > temp == true && j>0;
 ->
   l r
     5 5 3 2 1 0   j < 0, break;
   j   i
 ->                 arr[j+1] = temp
     4 5 3 2 1 0
 i = 1 迭代完成


       l r
 2.  4 5 3 2 1 0   5 > temp==3 -> arr[j+1] = arr[j]
       j i
     l r
     4 5 5 2 1 0   4 > temp==3 -> arr[j+1] = arr[j]
     j   i
   l r
     4 4 5 2 1 0   j<0 -> break;
   j     i
     3 4 5 2 1 0   arr[j+1] = temp;
     以此類推
```
