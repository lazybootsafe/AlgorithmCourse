# LeetCode 04|二维数组中的查找

## 原题地址

<https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/>

## 题意

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

我们来看样例：

~~~
现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。

给定 target = 20，返回 false。
~~~



 ## 题解

### 1.暴力解法

暴力方法，最简单也是自己最快想到的思路。两层for直接搜，第一层for控制n次，第二层for挨个比较，但是加了大小控制，比较到比目标数大的立马结束暴力；

代码如下：

~~~c
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size() && matrix[i][j] <= target; j++){ //控制大小
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }

~~~

### 2. 二分法

首先，因为数组的每一行和每一列都是递增的所以可以发现如下的规律：

![img](https://img-blog.csdn.net/20141027171806031?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvYWhmeXRhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

数字7是大矩阵的最小值，13是小矩阵的最小值，所以我们的思路就是先让查找的数x跟二维数组的对角线上的值进行比较（找到数组中对角线上第一个大于x的数的位置来缩小查找的范围）比如，我们查找12，那么查找的范围就可以锁定在两个部分，如下图所示：

![img](https://img-blog.csdn.net/20141027172348512?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvYWhmeXRhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)


此时，我们只要在这两部分中查找x即可，观察可发现这两个部分一个是一行数据（可视为一维数组）和一个是小矩阵。前一部分可以用二分查找（有序），后一部分可以直接遍历（应该还有更好的方法，我实现的时候是直接遍历）。

由于题目对m和n的大小关系没有做限制，这就增加了题目的难度（即找到二维数组中第一个大于x的数的位置边困难了），我的解决思路是根据m和n的大小关系分三种情况，

当m=n时最简单，在此不提，另外两种情况，分别是找一个小的方型矩阵，如果没有找到要找的位置，那么改变循环变量的值，继续在下一个小方型矩阵中寻找，直到没有小的方型矩阵为止。下面给出一个m>n的大致查找过程：

![img](https://img-blog.csdn.net/20141027173812036?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvYWhmeXRhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

主要解题思路如上所述，完整代码如下：

~~~c
#include<stdio.h>
#include<stdlib.h>
long a[1000][1000];
int m,n;
//二分查找 
int binarySearch(int tm1,int tn1,long x)
{
	int s,e,mid;
	s=tn1+1;
	e=n-1;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(a[tm1][mid]==x)
			return 1;
		else if(a[tm1][mid]<x)
		{
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	return 0;
}
//小矩阵遍历 
int binarySearch2(int tm2,int tn2,long x)
{
	int i,j;
	for(i=tm2;i<m;++i)
		for(j=0;j<=tn2;++j)
			if(a[i][j]==x)
				return 1;
	return 0;
}
int arraySearch(long x)
{
	int tm,tn;
	int r1,r2;
	if(m>n)
	{
		tm=0;
		tn=0;
		//查找位置的过程 
		while(tm<m)
		{
			if(a[tm][tn]==x)
			{
				return 1;
			}
			if(a[tm][tn]>x)
			{
				break;
			}
			if(tn==n-1)
			{
				tn=0;
				++tm;//进入下一个小型方阵 
			}
			else
			{
				++tn;
				++tm;
			}
		}
		//查找位置的过程 
		if(tm==m)
		{
			return binarySearch(tm-1,0,x);
		}
		else
		{
			//找到位置后，分别对两部分进行查找 
			r1=binarySearch(tm-1,tn-1,x);//二分查找 
			r2=binarySearch2(tm,tn-1,x);//小矩阵遍历 
			return (r1+r2);
		}
	}
	else if(m<n)
	{
		tm=0;
		tn=0;
		while(tn<n)
		{
			if(a[tm][tn]==x)
			{
				return 1;
			}
			if(a[tm][tn]>x)
			{
				break;
			}
			if(tm==m-1)
			{
				tm=0;
				++tn;
			}
			else
			{
				++tn;
				++tm;
			}
		}
		if(tn==n)
		{
			return binarySearch2(tn-1,0,x);
		}
		else
		{
			r1=binarySearch(tm-1,tn-1,x);
			r2=binarySearch2(tm,tn-1,x);
			return (r1+r2);
		}		
	}
	else
	{
		tm=0;
		tn=0;
		while(tm<m)
		{
			if(a[tm][tn]==x)
			{
				return 1;
			}
			if(a[tm][tn]>x)
			{
				break;
			}
			++tn;
			++tm;		
		}
		if(tm==m)
		{
			return 0;
		}
		else
		{
			r1=binarySearch(tm-1,tn-1,x);
			r2=binarySearch2(tm-1,tn-1,x);
			return (r1+r2);
		}
	}
}
int main()
{
	int i,j;
	long x;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		scanf("%ld",&x);
		for(i=0;i<m;++i)
			for(j=0;j<n;++j)
			{
				scanf("%ld",&a[i][j]);
			}
		if(arraySearch(x))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	
	return 0;
}
~~~

### 3.(最优)线性法(固定方向行走)，充分利用矩阵的有序性。

在矩阵当中行走，根据当前元素的大小选择行走方向。

+ 如果我们选择左上角为起点，那么当matrix[y][x] < target时，要去找下一个更大的元素与target比较，向下和向右都有可能，不知道从哪边走。同理以右下角为起点也不不确定行走方向。
+ 选择从右上角开始，如果matrix[y][x] < target，去找下一个更大的元素，就只能向下走。反之要去找比当前更小的元素，就选择往左走。（选择从左下角开始也是可行的）
+ 如果在行走过程中有相等元素，就返回true。如果坐标超出矩形范围，说明没有找到，返回false。

![img](https://img-blog.csdnimg.cn/20200602222421350.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDcyMzQ5Ng==,size_16,color_FFFFFF,t_70)

代码如下：

~~~c
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int i = 0;
        int j = matrix[0].size()-1;			//右上角出发
        while(i < matrix.size() && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] < target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }

~~~

