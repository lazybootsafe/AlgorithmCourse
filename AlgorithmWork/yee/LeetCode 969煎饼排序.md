# LeetCode 969|煎饼排序

+++

## 原题地址

<https://leetcode-cn.com/problems/pancake-sorting/>



##  题意

给定数组 A，我们可以对其进行煎饼翻转：我们选择一些正整数 k <= A.length，然后反转 A 的前 k 个元素的顺序。我们要执行零次或多次煎饼翻转（按顺序一次接一次地进行）以完成对数组 A 的排序。

返回能使 A 排序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * A.length 范围内的有效答案都将被判断为正确。

 

示例 1：

~~~
输入：[3,2,4,1]
输出：[4,2,4,3]
解释：
我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
初始状态 A = [3, 2, 4, 1]
第一次翻转后 (k=4): A = [1, 4, 2, 3]
第二次翻转后 (k=2): A = [4, 1, 2, 3]
第三次翻转后 (k=4): A = [3, 2, 1, 4]
第四次翻转后 (k=3): A = [1, 2, 3, 4]，此时已完成排序。 
~~~



示例 2：

~~~
输入：[1,2,3]
输出：[]
解释：
输入已经排序，因此不需要翻转任何内容。
请注意，其他可能的答案，如[3，3]，也将被接受。
~~~



## 题解

快速排序

1.找到最大值的位置K。
2.翻转最大值在内的前K个数字，此时最大值已经处于第一个位置。
3.翻转整个数组。此时最大值处于最后一个位置。
4.以此次类推，计算第二大数字的位置，进行操作。
5.注意：1）已经排好序的，直接返回。2）记录翻转的位置不是数组的下标

~~~c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdbool.h>

int max_value_postion(int *arr, int num) {
    int max_flag = 0;
    int i;
    for (i = 1; i < num; i++) {
        if (arr[i] > arr[max_flag]) {
            max_flag = i;
        }
    }

    return max_flag + 1;
}
void return_over_arr(int *arr, int num) {
    int i, j;
    int tmp;

    for (i = 0; i < num / 2; i++) {
         tmp = arr[i];
         arr[i] = arr[num - 1 - i];
         arr[num - 1 - i] = tmp;
    }

    return ;
}

bool isAscendSort(int *arr, int arrLenth) {
    int temp = 0;
    for (int i = 0; i < arrLenth; i++) {
        temp = arr[i];
        if (i < arrLenth - 1) {//防止数组下标越界
            if (temp > arr[i+1]) {//后一个元素比前一个大，非升序
                return false;
            }
        }
    }
    return true;
}
int* pancakeSort(int* A, int ASize, int* returnSize) {
    int i, k, j;
    int *returnarray;
    int index;

    if (ASize <= 1) {
        *returnSize = 0;
        return NULL;
    }

    bool flag = false;
    flag = isAscendSort(A, ASize);

    if (true == flag) {
        *returnSize = 0;
        return NULL;
    }

    returnarray = (int *)malloc(sizeof(int) * ASize * 10);

    for (i = 0, k = 0; i < ASize - 1; i++) {
        index = max_value_postion(A, ASize - i);
        return_over_arr(A, index);
        returnarray[k++] = index;
        return_over_arr(A, ASize - i);
        returnarray[k++] = ASize - i;
    }

    * returnSize = k;

    if (k > (ASize * 10)) {
        * returnSize = 0;
        return NULL;
    } else {
        return returnarray;
    }
}
~~~

