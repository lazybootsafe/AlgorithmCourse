# LeetCode 1403  |  非递增顺序的最小子序列

+++

## 原题地址

<https://leetcode-cn.com/problems/minimum-subsequence-in-non-increasing-order/>



## 题意

给你一个数组 nums，请你从中抽取一个子序列，满足该子序列的元素之和 严格 大于未包含在该子序列中的各元素之和。

如果存在多个解决方案，只需返回 长度最小 的子序列。如果仍然有多个解决方案，则返回 元素之和最大 的子序列。

与子数组不同的地方在于，「数组的子序列」不强调元素在原数组中的连续性，也就是说，它可以通过从数组中分离一些（也可能不分离）元素得到。

注意，题目数据保证满足所有约束条件的解决方案是 唯一 的。同时，返回的答案应当按 非递增顺序 排列。

 

示例 1：

~~~
输入：nums = [4,3,10,9,8]
输出：[10,9] 
解释：子序列 [10,9] 和 [10,8] 是最小的、满足元素之和大于其他各元素之和的子序列。但是 [10,9] 的元素之和最大。 
~~~

示例 2：

~~~
输入：nums = [4,4,7,6,7]
输出：[7,7,6] 
解释：子序列 [7,7] 的和为 14 ，不严格大于剩下的其他元素之和（14 = 4 + 4 + 6）。因此，[7,6,7] 是满足题意的最小子序列。注意，元素按非递增顺序返回。
~~~



## 题解

1.sum_total记录数组元素总和
2.从大元素到小元素的顺序放入子数组——申请一块大小为4×numsSize字节的内存    	buf：malloc函数
3.利用qsort()和cmp()实现快速排序（结果为升序）
4.sum_subarray记录子数组元素总和
5.对排序后的数组，从后往前遍历，sum_total递减;sum_subarray递增；buf内存大	小递增
6.直到子数组元素和>剩余元素和，结束

~~~c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b)                    //使用***qsort函数的cmp函数
{
    int m = *(int *)a;
    int n = *(int *)b;
    return m - n;
}

int* minSubsequence(int* nums, int numsSize, int* returnSize)    //returnSize是结果数组的大小
{
    int sum_total = 0;                                //统计所有元素的总和
    int sum_subarray = 0;                             //统计子数组所有元素的和

    int * buf = ( int * )malloc( sizeof( int ) * numsSize );   //在堆区申请一块内存

    for(int i=0;i<numsSize;i++)                      //得到sum_total
    {
        sum_total += nums[i];
    }

    qsort(nums, numsSize, sizeof(nums[0]), cmp);         //快速排序

    *returnSize =0;

    for(int i = numsSize-1 ; i>=0 ; i--)
    {
        sum_total -= nums[i];                     //剩余元素总和
        sum_subarray += nums[i];                  //子数列的总和
        *(buf + *returnSize) = nums[i];           //扩大内存
        ++ *returnSize;                     //结果数组长度+1---注意：++a 等同于 a+=1 ;跟 a++不一样

        if(sum_subarray > sum_total)                 //如果子数列元素和>其他元素和，结束
        {
            break;
        }

    }

    return buf;

}
~~~



