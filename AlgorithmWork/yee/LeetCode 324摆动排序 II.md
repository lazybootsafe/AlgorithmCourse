# LeetCode 324|摆动排序 II

+++

## 原题地址

<https://leetcode-cn.com/problems/wiggle-sort-ii/>



## 题意

给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

示例 1:

~~~
输入: nums = [1, 5, 1, 1, 6, 4]
输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
~~~



示例 2:

~~~
输入: nums = [1, 3, 2, 2, 3, 1]
输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
~~~



## 题解

排序，将数组分成两个数组，新建数组，偶数位保存小数，奇数位保存大数

+ 对数组进行升序快速排序
+ 设置两个索引left和right，把整个数组分成两个部分[0 , left] [left+1 , right]
+ 新建一个数组res，通过遍历，第0，2，4，6....的位置存放[0,left]里的元素，第1,3,5,7....的位置存放[left+1,right]里的元素
+ 最后将res复制到nums里



~~~c

//利用两个数组，分别反向插入

int cmp(const void* a, const void* b)
{
    int m = *(int*)a;
    int n = *(int*)b;
    return m-n;                 //升序
}

void wiggleSort(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(nums[0]), cmp);           //快速排序

    //将整个数组一分为二，[0 , left]的元素 < [letf+1 , right]的元素
    int left = (numsSize % 2 ? numsSize/2 : numsSize/2-1); //注意奇偶
    int right = numsSize - 1;

    int *res = (int*)malloc(sizeof(int) * numsSize);
    int index = 0;

    for(int i=0; i<numsSize; i++)
    {
        if(i % 2)                                          //1，3，5，7......的位置应是大数 
        {
            res[index] = nums[right];                      //res中保存大数
            index++;
            right--;
        }
        else                                               //0，2，4，6.....的位置应是小数
        {
            res[index] = nums[left];                      //res中保存小数
            index++;
            left--;
        }
    }

    memcpy(nums, res, sizeof(int)*numsSize);             //从存储区res复制n个字节到存储区nums
    //return nums;  void无返回值函数，不必返回
}
~~~

