# LeetCode-119|杨辉三角 II

## 原题地址

<https://leetcode.com/problems/pascals-triangle-ii/>

本题官方难度Easy，通过率大约49%。解决这一题的时候是可以套用上一题的方法的，但是我们也可以将他进行不断的改进从而得到更简的算法。

## 题意

给定一个非负索引 *k*，其中 *k* ≤ 33，返回杨辉三角的第 *k* 行

样例如下：

```
Input: 3
Output: [1,3,3,1]
```

## 题解

### 1.完全按照118题的思路。

~~~c
int* getRow(int rowIndex, int* returnSize) {   
    rowIndex += 1;
    *returnSize = rowIndex;//这里不能改为*returnSize=rowIndex + 1；不知道什么原因
    int** ret = (int**)malloc(sizeof(int) * (1 + rowIndex) * rowIndex / 2);
    for (int i = 0; i < rowIndex; i++) {
        ret[i] = (int*)malloc(sizeof(int) * (i + 1));
    }
    ret[0][0] = 1;
    for (int i = 1; i < rowIndex; i++) {
        ret[i][0] = 1;
        int j = 1;
        for (j = 1; j < i; j++) {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
        ret[i][j] = 1;
    }
    return ret[rowIndex - 1];
}

~~~



### 2. 我们其实并不需要那么多的存储空间，仅仅保留上一层的结果，就可以得到当前层的结果

~~~c
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* pre = (int*)malloc(sizeof(int) * (rowIndex + 1));
    int* cur = (int*)malloc(sizeof(int) * (rowIndex + 1));
    pre[0] = 1;
    cur[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        cur[0] = 1;
        cur[i] = 1;
        for (int j = 1; j < i; j++) {
            cur[j] = pre[j] + pre[j - 1];
        }
        for (int k = 0; k <= i; k++) {
            pre[k] = cur[k];
        }
    }
    return cur;
}
~~~

### 3.连保存上一层的结果都不需要，直接在原数组的基础上更改

~~~c
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* ret = (int*)malloc(sizeof(int) * (rowIndex + 1));
    int pre = 1;
    ret[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = 1; j < i; j++) {
            int tmp = ret[j];
            ret[j] += pre;
            pre = tmp;
        }
        ret[i] = 1;
    }
    return ret;
}

~~~

### 4.从后向前更改数组，这样不需要保存已经被覆盖的结果

~~~c
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* ret = (int*)malloc(sizeof(int) * (rowIndex + 1));
    memset(ret, 0, sizeof(int) * (rowIndex + 1));
    ret[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j >= 1; j--) {
            ret[j] += ret[j - 1];
        }
    }
    return ret;
}

~~~

