# LeetCode 1338|Reduce Array Size to The Half(数组大小减半)

## 原题地址

<https://leetcode.com/problems/reduce-array-size-to-the-half/>

## 题意

给你一个整数数组 `arr`。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。

返回至少能删除数组中的一半整数的整数集合的最小大小。

我们来看样例：

```
Input: arr = [7,7,7,7,7,7]
Output: 1

Input: arr = [1,9]
Output: 1
```

## 题解

+ 新建一个初始值为0的矩阵，记录输入矩阵中，每个数字出现的次数
+ 对新建的记录次数的矩阵元素进行降序排列
+ 对经过排序的矩阵，累加求和前K个元素，直到前K个元素的和>=输入数组长度的一半

代码如下：

~~~C
#define MAX_SIZE 100001
int Compare(const void *_a, const void *_b);
int minSetSize(int* arr, int arrSize)
{
    if (arr == NULL || arrSize <= 0) {
        return 0;
    }
    int *hashArr = (int *)malloc(sizeof(int) * MAX_SIZE);
    memset(hashArr, 0, sizeof(int) * MAX_SIZE);
    if (hashArr == NULL) {
        return -1;
    }
    int i;
    int result = 0;
    int halfValue = arrSize / 2;
    int tmp = 0;
    for (i = 0; i < arrSize; i++) {
        hashArr[arr[i]]++;

    }
    qsort(hashArr, MAX_SIZE, sizeof(int), Compare);
    for (i = 0; i < MAX_SIZE; i++) {
        if (hashArr != 0 && tmp < halfValue) {
            tmp = tmp + hashArr[i];
            result++;
        }
    }
    return result;
}
int Compare(const void *_a, const void *_b)
{
    int *a = (int *)_a;
    int *b = (int *)_b;
    return *b - *a;
}

~~~



