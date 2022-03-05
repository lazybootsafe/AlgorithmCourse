# 剑指 Offer 53 - I. 在排序数组中查找数字 I

+++

## 原题地址

<https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/>



## 题意

统计一个数字在排序数组中出现的次数。

示例 1:

~~~
输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
~~~

示例 2:

~~~
输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
~~~



## 题解

借鉴大佬两种不同的二分法思路：

+ 第一种是找到相同位置直接进行扩散查找，

~~~~c
//暴力二分法，使用二分法找到数组中和给定值相同的位置，然后从该位置为中心，查找该位置两边等于给定值的位置，记录总数并返回
int search(int* nums, int numsSize, int target){
    int left=0,right=numsSize-1,count=0;

    while(left <= right){
        int mid = left + (right - left) / 2;
        //当该位置的值等于给定值
        if(nums[mid] == target){
            //以该位置为中心，向两边扩散寻找和给定值相同的位置，每找到一个计数值加一
            int temp = mid;
            while(temp >= 0 && nums[temp] == target){
                temp--;
                count++;
            }
            mid++;
            while(mid < numsSize && nums[mid] == target){
                mid++;
                count++;
            }
            //注意，找到所有和给定值相同的位置后之后要直接跳出循环
            break;
        }else if(nums[mid]<target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    return count;
}
~~~~



+ 第二种是二分法求出左右边界

~~~c
//二分法，思路为使用二分法求出数组中出现的给定值的位置左右边界，先使用左闭右开区间求出右边界，同时判断当前位置区间右值是否等于给定值，如果不等于，说明当前数组不存在给定值，返回0，再使用左开右闭区间求出左边界，返回左右边界差值减一即可
int search(int* nums, int numsSize, int target){
    int n=0,m=numsSize-1;

    //二分法计算右边界
    while(n<=m){
        int mid=n+(m-n)/2;
        //思路是nums[mid]==target的情况下，右边界值一定落在[mid+1,m]之间，如果想求出右边界，就要使n=mid+1，又因为结果和nums[mid]<target相同，所以并入其中，这样当二分运算结束时，n就正好到达右边界的位置
        if(nums[mid]<=target){
            n=mid+1;
        }else{
            m=mid-1;
        }
    }
    int right=n;
    //因为经过上面的二分计算后，n到达右边界，而m则在右边界的左边一个位置的地方，如果这个位置在数组范围内，则一定等于给定值，如果该位置不等于给定值，说明该数组不存在给定值
    if(m>=0 && nums[m]!=target){
        return 0;
    }
    //复原用于二分计算的最大边界值
    n=0;
    m=numsSize-1;
    while(n<=m){
        int mid=n+(m-n)/2;
        //思路是nums[mid]==target的情况下，左边界值一定落在[n,mid-1]之间，如果想求出右边界，就要使m=mid-1，又因为结果和nums[mid]>target相同，所以并入其中，这样当二分运算结束时，m就正好到达左边界的位置
        if(nums[mid]<target){
            n=mid+1;
        }else{
            m=mid-1;
        }
    }
    int left=m;

    return right-left-1;
}
~~~



