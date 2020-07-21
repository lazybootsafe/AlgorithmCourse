# LeetCode 1260|Shift 2D Grid(二维网格迁移)

## 原题地址

<https://leetcode.com/problems/shift-2d-grid/>

## 题意

给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。

每次「迁移」操作将会引发下述活动：

    位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
    位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
    位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。

请你返回 k 次迁移操作后最终得到的 二维网格。

样例：

![img](https://assets.leetcode.com/uploads/2019/11/05/e1.png)

```
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]
```

## 题解

将二维变一维

+ 遍历一遍二维数组，放入同等大小的一维数组中

+ 利用memcpy函数将一维数组buf的尾部k个放到profix中，buf前面的放进befix中。继续利用memcpy拼接befix和profix

+ 将顺序整理好的buf一个一个读到需要返回的二维数组中。

  

  代码如下：

  ~~~c
  void CatK(int* buf, int size, int k) {
      int* profix = (int*)malloc(sizeof(int) * (size - k));
      int* befix = (int*)malloc(sizeof(int) * k);
      memcpy(profix, buf, sizeof(int) * (size - k));
      memcpy(befix, buf + (size - k), sizeof(int) * k);
      memcpy(buf, befix, sizeof(int) * k);
      memcpy(buf + k, profix, sizeof(int) * (size - k));
  }
  
  int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes)
  {
      *returnSize = gridSize;
      *returnColumnSizes = (int*)malloc(sizeof(int) * gridSize);
      int** ret = (int**)malloc(sizeof(int*) * gridSize);
      for (int i = 0; i < gridSize; i++) {
          ret[i] = (int*)malloc(sizeof(int) * (*gridColSize));
          (*returnColumnSizes)[i] = *gridColSize;
      }
  
      int* buf = (int*)malloc(sizeof(int) * gridSize * (*gridColSize));
      int p = 0;
      for(int i = 0; i < gridSize; i++) {
          for (int j = 0; j < *gridColSize; j++) {
              buf[p] = grid[i][j]; 
              p++;
          }
      }
      k = k % (gridSize * (*gridColSize));
      CatK(buf, gridSize * (*gridColSize), k);
      p = 0;
      for (int i = 0; i < gridSize; i++) {
          for (int j = 0; j < *gridColSize; j++) {
              ret[i][j] = buf[p];
              p++;
          }
      }
      return ret;
  }
  ~~~

  

  