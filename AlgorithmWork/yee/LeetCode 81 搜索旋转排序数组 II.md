# LeetCode 81| 搜索旋转排序数组 II

+++

## 原题地址

<https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/>



## 题意

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。



示例 1:

~~~
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
~~~

示例 2:

~~~ 
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
~~~



## 题解

二分法查找，将给定值与最右值比较
1，如果nums[mid] > nums[right]，说明mid左侧是递增区间
1）target落在左侧递增区间内，则right = mid - 1;
2）否则left = mid + 1;
2，如果nums[mid] < nums[right]，说明mid右侧是递增区间
1）target落在右侧递增区间内，则left = mid + 1;
2）否则right = mid - 1;
3）如果nums[mid] = nums[right]，不能确认递增区间的位置，所以逐步移动右侧指针

~~~c

#define TRUE 1
#define FALSE 0
bool search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return TRUE;
        }

        if (nums[mid] > nums[right]) {
            if ((target >= nums[left]) && (target < nums[mid])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (nums[mid] < nums[right]) {
            if ((target > nums[mid]) && (target <= nums[right])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            right--;
        }
    }

    return FALSE;
}
~~~




