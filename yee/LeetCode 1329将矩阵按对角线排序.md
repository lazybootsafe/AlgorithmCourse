# LeetCode 1329|将矩阵按对角线排序

+++

## 原题地址

<https://leetcode-cn.com/problems/sort-the-matrix-diagonally/>



## 题意

给你一个 `m * n` 的整数矩阵 `mat` ，请你将同一条对角线上的元素（从左上到右下）按升序排序后，返回排好序的矩阵。

示例 1：

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/25/1482_example_1_2.png)

~~~
输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
~~~



## 题解

运用冒泡排序：
 我们需要用到三个for循环
 第一个是次数
 第二个行
 第三个是列
 **我们是斜着比较，即 a[i][j] 与  a[i+1][j+1]相比较**

1. 对于次数来说，就是对角线最大元素个数-1即可，也等于行数-1；
2. 对于行数，我们是matSize - 1 - i，为什么是这样呢，因为我们每次都把最大的数字放在了最后边，即每排一次，即可减少一行。



~~~c
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int i,j,k;
    for(i = 0; i < matSize - 1; i++){
        for(j = 0; j < matSize - 1 - i; j++){
            for(k = 0; k < matColSize[0] - 1; k++){
                if(mat[j][k] > mat[j+1][k+1]){
                    int temp;
                    temp = mat[j][k];
                    mat[j][k] = mat[j+1][k+1];
                    mat[j+1][k+1] = temp;
                }
            }
        }
    }
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    return mat;
}

~~~

