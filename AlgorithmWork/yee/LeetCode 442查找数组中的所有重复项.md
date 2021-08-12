# LeetCode 442|查找数组中的所有重复项

+++

## 原题地址

<https://leetcode.com/problems/find-all-duplicates-in-an-array/>



## 题意

给定一个整数数组，1≤A [1]≤ *Ñ*（*Ñ* =数组的大小），一些元件出现两次以及其他出现一次。查找在此数组中出现两次的所有元素。

我们来看样例：

```
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
```

## 题解

纯属学习，一开始想不到这么高效的方法
最笨的办法是排序后再遍历一遍，挑出出现了2次的数字
再次的办法是借助辅助空间，针对数组中出现的数字进行计数，最后挑出出现了2次的数字

最优解法：
遇到nums[i]那么就把下标为nums[i]-1的这个元素符号进行反转：

如果为正，那么就把下标为nums[i]-1的元素符号更换
如果为负，说明之前下标为nums[i]-1的元素已经存在了，那么就可以立马找到重复的那个数就是nums[i].
就可以直接把重复的结果找到。

代码如下：

~~~c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    if (nums == NULL || numsSize < 2) {
        return NULL;
    }
    int *ret = (int *)malloc(numsSize / 2 * sizeof(int));
    memset(ret, 0, numsSize / 2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int absNum = abs(nums[i]);
        if (absNum > numsSize) {
            continue;
        }
        if (nums[absNum - 1] < 0) {
            ret[*returnSize] = absNum;
            *returnSize = *returnSize + 1;
        }else {
            nums[absNum - 1] = -nums[absNum - 1];
        }
    }
    return ret;
}
~~~

