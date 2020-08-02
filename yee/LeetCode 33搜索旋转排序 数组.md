# LeetCode 33|搜索旋转排序数组

+++

## 原题地址

<https://leetcode-cn.com/problems/search-in-rotated-sorted-array/>



## 题意

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。



示例 1:

~~~
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
~~~

示例 2:

~~~
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
~~~



## 题解

C语言 二分法搜索

1、将区间分为前半段和后半段，其中必定有一段是单调的
 2、判断单调的一段是否包含target，如果包含，就在单调段寻找，否则在另一段寻找
 3、不断用二分法搜寻，知道head和tail相差1，退出后判断head和tail是否命中目标，有则返回命中位置，否则返回-1

~~~c
int search(int* nums, int numsSize, int target){
    if (numsSize == 0) {
        return -1;
    }
    int head = 0;
    int tail = numsSize - 1;
    int mid;
    while (head < tail) {
        mid = (head + tail) / 2;

        // 先判断头和尾是否满足要求，是的话直接返回地址
        if (nums[head] == target) {
            return head;
        } else if (nums[tail] == target) {
            return tail;
        } 

        // 如果head等于mid，则必定是head和tail相差1，如果不退出会陷入死循环
        if (head == mid) {
            break;
        }
        // 先判断前面部分是否是单调
        if (nums[head] < nums[mid]) {
            if (nums[head] < target && nums[mid] > target) {  // 判断目标是否在单调区间内，是的话则将尾部赋值为前段区间的尾部
                tail = mid; 
            } else {                                          // 如果不在单调区间内，则将头部赋值为前段区间的尾部 
                head = mid;
            }
        } else {                                              // 如果前段不是单调，则后端必定是单调
            if (nums[mid] < target && nums[tail] > target) {  // 判断目标是否在后段的单调区间内，是的话则将头部赋值为后段区间的头部
                head = mid;
            } else {
                tail = mid;                                   // 如果不在单调区间内，则将尾部赋值为后段区间的头部
            }

        }
    }

    // 判断head和tail是否就是命中的位置，如果是则返回
    if (nums[head] == target) {
        return head;
    } else if (nums[tail] == target) {
        return tail;
    }
    return -1;
}
~~~

