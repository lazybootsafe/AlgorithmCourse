# LeetCode 189|数组基础，利用分步的思想，定义一个反转数组的函数，进行三次反转，进而得到目标数组。

## LeetCode第189题，Rotate Array (数组的循环移位)

## 原题地址

<https://leetcode.com/problems/rotate-array/>

本题得官方难度是Easy，通过率大约35%，总体来说，如果不考虑题中对空间复杂度的要求，我觉得整体难度是偏简单的，就是一道数组的基础题。对数组熟悉的同学，问题不大。但是我这样的解法是超时了的，这就需要我们找寻其他的解决方案。

## 题意

给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

我们来看样例：

~~~
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
~~~

由此可知，将一个含有n个元素的数组，旋转k步，即**将右边的k个元素，从数组尾部依次移动到数组的头部**。

## 题解

### 1.暴力解法

在刚看到这个题目时，脑子里第一时间想到的，最简单的解法：创建一个`temp`数组整个把原数组复制过来，然后再按照旋转后的结果逐个元素地覆盖原数组。代码如下：

~~~c
#include<stdio.h>
#define Max 10
void rotate(int* nums,int size,int k)
{
	int i,j;
	int temp[size];
	
	//复制数组元素
	for(i=0;i<size;i++)
		temp[i]=nums[i];
	
	//把后k个元素覆盖到原数组的前k个位置上
	j=0;
	for(i=size-k;i<size;i++,j++)
		nums[j]=temp[i];
		
	//剩余部分按顺序覆盖
	for(i=0;i<size-k;i++,j++)
		nums[j]=temp[i];
		
	printf("新数组元素顺序为:");
	for(i=0;i<size;i++)
		printf("%d ",nums[i]); 
}

int main()
{
	int nums[Max];
	int k;
	int i;
	printf("please enter the numbers:");
	for(i=0;i<Max;i++)
		scanf("%d",&nums[i]);
	printf("please enter the k:");
	scanf("%d",&k);
	
	rotate(nums,Max,k);
	return 0;
}
~~~

时间复杂度，复制数组为`n`，覆盖原数组也是`n`，所以总的时间复杂度为*O*(*n*)。
 空间复杂度，因为有`temp`数组的存在，所以需要`n`个元素的空间，因此空间复杂度也是*O*(*n*)

### 2.循环嵌套

我们可以借助循环嵌套（两层for循环处理）模拟右移过程，总共移动k次，外层就循环k次；内层循环则是将所有前n-1个元素向后移，并将最后一个元素记录下来，存放在第一个元素去，以实现逐个循环的效果

~~~c
#include<stdio.h>
#define Max 10
void rotate(int* nums,int size,int k)
{
	k=k%size;//可以得出数据移动了几个位置,若k>numsSize则移动位置为余数；
	int i=0,j=0;
	for(i=0;i<k;i++)//控制循环次数(k)
	{
		int temp=nums[size-1];
		for(j=size-1;j>0;j--)//元素后移 
		{
			nums[j]=nums[j-1];
		}
		nums[0]=temp;
	}
	
	printf("新数组元素顺序为:");
	for(i=0;i<size;i++)
		printf("%d ",nums[i]); 
}

int main()
{
	int nums[Max];
	int k;
	int i;
	printf("please enter the numbers:");
	for(i=0;i<Max;i++)
		scanf("%d",&nums[i]);
	printf("please enter the k:");
	scanf("%d",&k);
	
	rotate(nums,Max,k);
	return 0;
}
~~~

+ 这种思路很好，特别是k=k%size,考虑到了k>size的情况，这样就减少了不必要的循环次数，节省了时间；
+ 但值得注意的是，当数据过大，则容易超时，显然，代码超时了

### 3.三反转

这个解法是最巧妙的，我想不出来……这也是最符合旋转数组这一标题的。
 ① 将整个数组翻转（理解：后移k位其实是将原数组后k位移动到了最前面，但是前后顺序不变。直接翻转后，已经将后k位移动到最前面了，只是顺序相反。）
 ② 将前k位翻转
 ③ 将后n-k位翻转

来看具体例子：

~~~
1 2 3 4 5 6 7；k=3--->5 6 7 1 2 3 4
(1)将整个数组倒序:
7 6 5 4 3 2 1
(2)将前3位进行倒序:
5 6 7
(3)将后四位进行倒序:
1 2 3 4

最后得到的就是:5 6 7 1 2 3 4

~~~

代码如下：

~~~c
#include<stdio.h>
#define Max 10
void reverse(int* nums,int left,int right)
{
	while(left<right)
	{
		int temp=nums[left];
		nums[left++]=nums[right];
		nums[right--]=temp;
	}
}

void rotate(int* nums,int size,int k)
{
	k=k%size;//若k>numsSize则移动位置为余数
	
	//先整体倒序
	reverse(nums,0,size-1);
	// 前k个倒序
	reverse(nums,0,k-1);
    //后n-k个倒序 
    reverse(nums,k,size-1);
	
	printf("新数组元素顺序为:");
	for(int i=0;i<size;i++)
		printf("%d ",nums[i]); 
}

int main()
{
	int nums[Max];
	int k;
	int i;
	printf("please enter the numbers:");
	for(i=0;i<Max;i++)
		scanf("%d",&nums[i]);
	printf("please enter the k:");
	scanf("%d",&k);
	
	rotate(nums,Max,k);
	return 0;
}
~~~

这种三反转的方法理解起来更加容易，而且也不会超时

## 总结

在这题中，我们面临的问题就是操作数组，给出的三种方法我觉得算法复杂度都差不多，就是空间复杂度有所差异，也因此带来的编码复杂度也有所不同。相对来说，第三种方法更加简单，但是比较难想到；第一种方法虽然比较容易想到，但是细节方面考虑的还不是很到位。

