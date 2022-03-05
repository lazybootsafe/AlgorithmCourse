# LeetCode167|Two Sum II - Input array is sorted(两数之和 II - 输入有序数组)

## 原题地址

<https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/>

本体官方难度Easy,通过率大约54%,如果对二分法有一定的了解，题目整体来说就是一道简单题。

## 题意

给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2

我们来看样例：

~~~
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
~~~

## 题解

### 1.暴力解法

当时脑海中首先想到的解决方案是通过两次循环，每次循环遍历列表。

代码如下：

~~~c
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i, j, flg = 0;

    for (i = 0; i < numbersSize - 1; i++){
        for (j = i + 1; j < numbersSize; j++){
            if (numbers[i] + numbers[j] == target){
                flg = 1;
                break;
            }
        }
        if (flg || numbers[i] > target)
            break;
    }
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int) * 2);
    res[0] = i + 1;
    res[1] = j + 1;
    return res;
}

~~~

这种算法的时间复杂度是O(n^2)，很明显，这种暴力解法在这问题中显得很蠢，所以需要寻找其他的解决方案。

### 2.二分法

我们已经知道这个数据是有序的，那么我们就应该想下使用二分搜索法是不是可以用于这个问题呢？我们可以每次判断`target-num[i]`对应的值是否在`num[i+1:]`中，这个时候算法的复杂度变成了`O(nlogn)`。

代码如下：

~~~c

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left, right, i, flag = 0,mid;
    for(i=0;i<numbersSize-1;i++){
        left = i + 1,right = numbersSize - 1;
        while(left<=right){
            mid = (left+right)/2;
            if(numbers[i]+numbers[mid]>target){
                right = mid - 1;
            }else if(numbers[i]+numbers[mid]<target){
                left = mid + 1;
            }else{
                flag = 1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    *returnSize = 2;
    int *res = calloc(2,sizeof(int));
    res[0] = i + 1;
    res[1] = mid + 1;
    return res;
}

~~~

虽然这种解法的复杂度比第一种小，但我们还是应该思考下有没有`O(n)`级别的做法。具体见下一种解法。

### 3.双指针

我们可以这样想，我们首先判断首尾两项的和是不是target，如果比target小，那么我们左边+1位置的数（比左边位置的数大）再和右相相加，继续判断。如果比target大，那么我们右边-1位置的数（比右边位置的数小）再和左相相加，继续判断。我们通过这样不断放缩的过程，就可以在O(n)的时间复杂度内找到对应的坐标位置。

代码如下：

~~~c
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int low = 0,high = numbersSize - 1;

    while(low < high){
        int sum = numbers[low] + numbers[high];
        if(sum > target){
            high -= 1;
        }else if(sum < target){
            low += 1;
        }else{
            break;
        }
    }
    *returnSize = 2;
    int *res = calloc(2,sizeof(int));
    res[0] = low + 1;
    res[1] = high + 1;
    return res;
}

~~~

这个方法不是我想出来的，但我觉得里面很关键的一个思路就是题中已经说他是一个排好序的数组了，所以不用像前面那么复杂的找。所以有时候利用好题目中的已知条件也是很关键的。

