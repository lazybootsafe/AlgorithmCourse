# LeetCode 905|按奇偶排序数组 ||

+++

## 原题地址

<https://leetcode-cn.com/problems/sort-array-by-parity-ii/>



##  题意

给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

~~~
输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
~~~



## 题解

这里可以理解为选择排序的变体，算法思路为：

+ 依次比较数组元素A[i]与i的奇偶性，如果相同则继续下一个元
+ 如果不同，则从i+1依次往后查找奇偶性与i相同的第一个元素A[j]，并交换A[i]与A[j]
+ 循环i直到数组遍历完毕

~~~c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
    int i, j;

    for (i = 0; i < ASize - 1; i++) {
        if ((A[i] & 0x1) != (i & 0x1)) {
            for (j = i+1; j < ASize; j++) {
                if ((A[j] & 0x1) == (i & 0x1)) {
                    int tmp = A[i];
                    A[i] = A[j];
                    A[j] = tmp;
                    break;
                }
            }
        }
    }
    *returnSize = ASize;
    return A;
}
~~~

