# LeetCode 27|Remove Element(移除元素)

## 原题地址

<https://leetcode.com/problems/remove-element/>

本体官方难度Medium,通过率大约48%,只要就一定的数组基础，就可以很容易解决。

## 题意

给你一个数组 *nums* 和一个值 *val*，你需要原地移除所有数值等于 *val* 的元素，并返回移除后数组的新长度。

我们来看样例：

~~~
Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
~~~

## 题解

按序扫描数组，同时使用一个count=0来计数。
 1.当扫描到的元素等于val时，则count++，表示下一个不等于val的元素需要往前挪count个位置。
 2.当扫描的元素不等于val时，该元素往前挪count个位置
 3.扫描结束后返回numsSize-count。

代码如下：

~~~C
int removeElement(int* nums, int numsSize, int val){
    if(numsSize==0){
        return 0;
    }
    int i=0,count=0;
    while(i<numsSize){
        if(nums[i]==val){
            i++;
            count++;
        }else{
            nums[i-count]=nums[i];
            i++;
        }
    }
    return numsSize-count;
}

~~~





