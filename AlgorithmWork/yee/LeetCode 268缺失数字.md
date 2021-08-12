# LeetCode 268|缺失数字

+++

## 原题地址

<https://leetcode.com/problems/missing-number/>



## 题意

给定一个数组，其中包含来自的*n个*不同的数字`0, 1, 2, ..., n`，请找到该数组中缺少的一个

我们来看样例：

```
Input: [3,0,1]
Output: 2
```



## 题解

法一：先求0到n的和，再减去数组每一项，返回结果即可。

~~~c
int missingNumber(int* nums, int numsSize){
    int i=numsSize,sum=(1+numsSize)*numsSize/2;
    while(i--) sum=sum-nums[i];
    return sum;
}
~~~

法二：先将数组元素从小到大排列，再从第一个元素开始，当坐标与该坐标对应的数字不相等时返回，全部相等，则返回数组的长度。

~~~c
int missingNumber(int* nums, int numsSize){
    int i,j,min,min_index;
    for(i=0;i<numsSize;i++){
        min=nums[i];
        min_index=i;
        for(j=i;j<numsSize;j++){
            if(nums[j]<min){
                min=nums[j];
                min_index=j;
            }
        }
        j=nums[i];
        nums[i]=min;
        nums[min_index]=j;
    }
    for(i=0;i<numsSize;i++)
        if(nums[i]!=i) return i;
    return numsSize;
}
~~~

