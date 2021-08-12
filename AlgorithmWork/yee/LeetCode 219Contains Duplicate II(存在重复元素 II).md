# LeetCode 219|Contains Duplicate II(存在重复元素 II)

## 原题地址

<https://leetcode.com/problems/contains-duplicate-ii/>

本题得官方难度是Easy，通过率大约38%，总体来说，如果不考虑题中对空间复杂度的要求，我觉得整体难度是偏简单的，就是一道数组的基础题。对数组熟悉的同学，问题不大。但是我这样的解法是超时了的，这就需要我们找寻其他的解决方案。

## 题意

给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值至多为 k。

我们来看样例：

```
Input: nums = [1,2,3,1], k = 3
Output: true

Input: nums = [1,0,1,1], k = 1
Output: true
```

## 题解

### 1.暴力解法

两层 for 循环暴力判断：

~~~c
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        int limit = i+k >= numsSize? numsSize: i+k+1;
        
        for (int j = i+1; j < limit; j++) {
            if (nums[j] == nums[i])
                return true;
        }
    }            
    
    return false;
}

~~~

显然时间太慢，不符合要求

### 2.利用排序

我第一次解答使用的算法，后来提交发现运行超时，然后参考了他人的算法，发现很多人的方法是先将数组进行排序，然后再比较相邻两个元素的值，若一样则返回true，否则false：

~~~c
bool containsDuplicate(int* nums, int numsSize)
{
    if(numsSize < 2)
    {
        return false;
    }
    int i = 0;
    int j = 0;

    for(i = 0;i< numsSize-1;i++)
    {
        for(j = i+1;j<numsSize;j++)
        {
            if(nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}

~~~

### 3.先排序(调用c库的快排)，然后通过查看相邻元素来判断是否存在重复(成功)

> 分析：
>
> 找数组中是否有重复项可按数元素数量分为两类：
>
> 1.没有或只有一个元素则直接返回0（没有重复项）
>
> 2.有多个元素（<2）则再进行判断
>
> 一，先将数组排一下序就可以很好的解决查看是否有重复项的问题了
>
> 将相邻的两个元素比较大小看是否相等，相等的化返回1（有重复项）
>
> 从头遍历比较到最后都没有的化，返回0（没有重复项）

排序的话这里是运用了Ç库里的快排函数

~~~c
#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
int comp(const void *a, const void *b)//比较函数
{
	return *(int*)a - *(int*)b;
}
int containsDuplicate(int* nums, int numsSize)
{
	if (numsSize + 1 <= 2)//一个数或没有数时直接返回0没有重复
	{
		return 0;
	}
	qsort(nums, numsSize, sizeof(int), comp);//快排
	for (int i = 0; i < numsSize - 1; i++)//相邻筛选
	{
		if (nums[i] == nums[i + 1])
			return 1;
	}
	return 0;
}
 
int main()
{
	int nums1[4] = { 1, 2, 3, 1 };
	int nums2[4] = { 1, 2, 3, 4 };
	int nums3[10] = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	int ret1 = containsDuplicate(nums1, 4);
	int ret2 = containsDuplicate(nums2, 4);
	int ret3 = containsDuplicate(nums3, 10);
	printf("%d \n", ret1);
	printf("%d \n", ret2);
	printf("%d \n", ret3);
	system("pause");
	return 0;
}
~~~

