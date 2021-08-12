# LeetCode  1005 |   K 次取反后最大化的数组和

+++

## 原题地址

<https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/>



## 题意

给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）

以这种方式修改数组后，返回数组可能的最大和。

 

示例 1：

~~~~
输入：A = [4,2,3], K = 1
输出：5
解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
~~~~

示例 2：

~~~
输入：A = [3,-1,0,2], K = 3
输出：6
解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]
~~~



## 题解

首先对数组进行从小到大排序，尽量多的将负值变为正值，每将一个负值变为正值，K减1，有如下两种情形：

1.当K = 0时，数组中的值全部为正值或是还剩余部分负值，将数组中的整数求和并返回；
2.当K > 0时，数组中的值已经全部为正值，将数组中最小的正值根据K的奇偶赋予正负号，然后求和并返回结果。

~~~c
int cmpfunc(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int largestSumAfterKNegations(int* A, int ASize, int K){
    int sum = 0;
    int idx = 0; // 保存全部正数的最小值的索引

    qsort(A, ASize, sizeof(int), cmpfunc); // 对数组中的值从小到大排序

    for(int i = 0; A[i] < 0 && K > 0; ++i){ // 将数组中的负值变为正值
        A[i] = abs(A[i]);
        idx = A[idx] < A[i] ? idx : i;
        K--;
    }

    if(K % 2 == 1){ // 当k>0，即此时数组中全为正值，K为奇数时，将最小的正数变为负数
        idx = A[idx] < A[idx + 1] ? idx : idx + 1;
        A[idx] *= -1;
    }

    for(int i = 0; i < ASize; ++i){ // 将数组中的所有数值加和
        sum += A[i];
    }
    return sum;
}
~~~



