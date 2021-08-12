# LeetCode 33|搜索旋转排序数组

+++

## 原题地址

<https://leetcode.com/problems/search-in-rotated-sorted-array/>

本题的官方难度是Medium，通过率大约35%，总体来说，如果你对二分法比较熟悉的话，那这就是一道基础题，整体偏简单。

## 题意

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 

我们来看样例：

~~~
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
~~~



## 题解

可以发现规律，对于任意一个旋转排序数组nums，设数组的第一个元素位置为left，最后一个元素位置为right，则必有：

[left,mid]区间或者[mid,right]区间至少有一个区间是完全有序的，

例如： 对于旋转数组 3 4 5 6 7 1 2，left=0，right=6，mid(left+right)/2=3,
			[left,mid]=>[0,3]区间所有元素为3 4 5 6
			[mid,right]=>[3,6]区间所有元素为6 7 1 2
显然左半边区间是有序的，同时，判断是否有序只需要判断左半边区间的左端点nums[0]<nums[3]是否成立即可。

利用这个特性，我们可以实现算法如下：
首先令 i=0,j=numSize-1
当i<=j时执行以下步骤：

计算出mid=(i+j)/2,判断如果nums[mid]==target，则直接返回mid
如果左半边区间[i,mid)区间有序（注意区间的一定时左边闭区间，右边因为mid已经判断了，可以是开区间）要分两种情况：

①如果target的值介于该区间内，则继续进入该区间搜索，j=mid-1

②如果target的值不介于该区间，则说明target要么不存在，要么再另外一个区间，而存不存在暂时不能判断，所以直接进入另外一个区间继续搜索，i=mid+1
如果左半边区间无序，那右半边区间一定是有序的，判断步骤和第二步相仿。

代码如下：

~~~C
int search(int* nums, int numsSize, int target){
    int i=0,j=numsSize-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(nums[mid]==target){
                return mid;
        }
        //当(mid,j]区间元素有序时
        if(nums[mid]<nums[j]){
            //如果target在(mid,j]区间时
            if(nums[mid]<target&&nums[j]>=target){
                i=mid+1;
            }
             //如果target在[i,mid)区间时
            else{
                j=mid-1;
            }
        }
        //当[i,mid)区间元素有序时
        else{
            if(nums[mid]>target&&nums[i]<=target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }//nums[i]<nums[mid]
    }
    return -1;
}

~~~

