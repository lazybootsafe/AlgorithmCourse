# LeetCode 1356| 根据数字二进制下 1 的数目排序

+++

## 原题地址

<https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/>



## 题意

给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。

如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。

请你返回排序后的数组。

 

示例 1：

~~~
输入：arr = [0,1,2,3,4,5,6,7,8]
输出：[0,1,2,4,8,3,5,6,7]
解释：[0] 是唯一一个有 0 个 1 的数。
[1,2,4,8] 都有 1 个 1 。
[3,5,6] 有 2 个 1 。
[7] 有 3 个 1 。
按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
~~~



示例 2：

~~~
输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
输出：[1,2,4,8,16,32,64,128,256,512,1024]
解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
~~~



## 题解

根据数字二进制下 1 的数目排序，需要进行如下步骤：

+ 获取每个数组元素二进制下 1 的数目；

+ 写一个 cmp 函数，然后调用 qsort 函数。

​        cmp 函数注意点：

![image.png](https://pic.leetcode-cn.com/9f2e811c86f3aa6e5a56813a6879b5f34e03153197034573da1802a48e5544d9-image.png)



~~~c
int getNum1(int n) {
    int cnt = 0;
    while (n > 0) {
        n &= (n - 1);
        cnt++;
    }

    return cnt;
}

int cmp(const void *a, const void *b) {
    int numa1 = *(int *)a, numb1 = *(int *)b;
    int c = getNum1(numa1), d = getNum1(numb1);

    return c == d ? numa1 - numb1 : c - d;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), cmp);

    return arr;
}
~~~

