# LeetCode 912|排序基础，直接调用C语言的qsort库函数

## LeetCode第912题，Sort an Array(数组排序)

## 原题地址

<https://leetcode.com/problems/sort-an-array/>

本体官方难度Medium,通过率大约64%,总的来说，只要对C语言的qsort函数了解，题目整体来说就是一道简单题。



## 题意

给你一个整数数组 `nums`，将该数组升序排列。

我们来看样例：

~~~
Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
~~~

## 题解

看到这个题目时，我首先想到的是冒泡排序或者选择排序，但不幸的是，这两种方式提交的代码都超时了。所以学习了下别人的解题方法，发现调用C语言的qsort函数就可以很简单的解决这个问题。

> C语言的qsort函数用法如下：
>
> qsort 的函数原型是void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
>
> ### 参数
>
> - **base**-- 指向要排序的数组的第一个元素的指针。
>
> - **nitems**-- 由 base 指向的数组中元素的个数。
>
> - **size**-- 数组中每个元素的大小，以字节为单位。
>
> - **compar**-- 用来比较两个元素的函数，即函数指针（回调函数）
>
>   > **回调函数：**
>   >
>   > 回调函数就是一个通过函数指针调用的函数。如果把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，就说这是回调函数。

> **compar参数**
>
> compar参数指向一个比较两个元素的函数。比较函数的原型应该像下面这样
>
> compare( (void *) & elem1, (void *) & elem2 );
>
> | Compare 函数的返回值 | 描述                    |
> | -------------------- | ----------------------- |
> | < 0                  | elem1将被排在elem2前面  |
> | 0                    | elem1 等于 elem2        |
> | > 0                  | elem1 将被排在elem2后面 |

​		具体调用方法我们可以根据下面这个例子来进一步理解：

~~~c
//对一维数组的排序实例（从小到大排序）：
#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void*b)
{
return *(int*)a-*(int*)b;
}
int main()
{
int i=0;
int *array;
int n;
scanf("%d",&n);
array=(int*)malloc(n*sizeof(int));
 
for(;i<n;i++)
{
scanf("%d",(array+i));
}
qsort(array,n,sizeof(int),comp);
for(i=0;i<n;i++)
{
printf("%d\t",array[i]);
}
return 0;
}
~~~

所以本题的代码如下：

~~~c
#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
int compare(int *a,int *b)
{
	return *a-*b;
}

int* sortarray(int *nums,int numsize,int *returnsize)
{
	qsort(nums,numsize,sizeof(nums[0]),compare);
	*returnsize=numsize;//让返回的数组大小等于nums数组的大小,否则会报内存溢出的错误
	
	return nums;
}

int main()
{
	int n,i,*p;
	printf("please enter the number of the array:");
	scanf("%d",&n);
	int nums[n];
	printf("please enter the numbers:");
	for(i=0;i<n;i++)
		scanf("%d",&nums[i]);
	
	p=sortarray(nums,n,p);	
	printf("The sorted array is:");
	for(i=0;i<n;i++)
		printf("%d",nums[i]);
		
	return 0;
}
~~~

