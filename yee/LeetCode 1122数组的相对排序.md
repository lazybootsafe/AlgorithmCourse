# LeetCode 1122|数组的相对排序

+++

## 原题地址

<https://leetcode-cn.com/problems/relative-sort-array/>



## 题意

给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

~~~
输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
~~~



## 题解

构造qsort的排列方式
构造一个结构体
具有如下的两个元素：
元素1： arr2的下角标
元素2： arr1的值
compare功能如下：
当下角标非初始化值时，按照下角标从小到大排列
当小角标相等时，按照元素2的值从小到大排列

~~~c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_INT 0x7FFFFFFF
typedef struct map {
    int num;
    int id;
}MAP;

int compare(const void* a, const void* b)
{
    if ((*(MAP*)a).id == (*(MAP*)b).id) {
        return (*(MAP*)a).num - (*(MAP*)b).num;
    } else {
        return (*(MAP*)a).id - (*(MAP*)b).id;
    }
}
void HASH(MAP* hash, int* src, int sizesrc, int * dst, int dstsize)
{
    for (int i = 0; i < sizesrc; i++) {
        hash[i].num = src[i];
        hash[i].id = MAX_INT;
        for (int j = 0; j < dstsize; j++) {
            if (src[i] == dst[j]) {
                hash[i].id = j;
                break;                
            }
        }        
    }
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    MAP * hash = (MAP*)malloc(sizeof(MAP) * arr1Size);
    int * ans  = (int *)malloc(sizeof(int) * arr1Size);
    HASH(hash, arr1, arr1Size, arr2, arr2Size);
    qsort(hash, arr1Size, sizeof(MAP), compare);
    
    for (int i = 0; i < arr1Size; i++) {
        ans[i] = hash[i].num;
    }
    *returnSize = arr1Size;
    return ans;
}
~~~

