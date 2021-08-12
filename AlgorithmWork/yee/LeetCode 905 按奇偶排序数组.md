# LeetCode 905|按奇偶排序数组

+++

## 原题地址

<https://leetcode-cn.com/problems/sort-array-by-parity/>



## 题意

给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

示例：

~~~
输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
~~~



## 题解

大概有几种   

1. 新建一个数组，对原数组进行遍历，偶数从头部放进去，奇数从尾部放进去。

2. 从前往后找奇数，从后往前找偶数，然后交换。
3. 双层循环，外循环找奇数，内循环找偶数，然后交换

~~~c
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int *num = (int *)malloc(sizeof(int)*ASize);
    *returnSize=ASize;
    int i,j;
    for(i=0;i<ASize;i++) {
        if(A[i] % 2 == 1) {//是奇数，往后放
            for(j=ASize-1;j>=0;j--) {
                if(j > i) {
                    if(A[j] % 2 == 0) {//是偶数，往前放
                        int temp = A[j];
                        A[j] = A[i];
                        A[i] = temp;
                    }
                }
            }
        }
    } 
    for(i=0;i<ASize;i++) {
        num[i]=A[i];
    }
    return num;   
}
~~~

