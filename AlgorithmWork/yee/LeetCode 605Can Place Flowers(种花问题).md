# LeetCode 605|Can Place Flowers(种花问题)

## 原题地址

<https://leetcode.com/problems/can-place-flowers/>

本题得官方难度是Easy，通过率大约32%，这道题目做得一塌糊涂，主要是没有分析所有的可能性，虽然是一道简单的题目，但是如果不能分析出所有的可能性，这道题也是做不对的。这也是这道题通过率比较低的原因。

## 题意

假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

我们来看样例：

~~~
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True

Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
~~~

## 题解

这道题目虽然简单，但最关键的还是要分析出所有的可能性；

+ 首先考虑全是0的情况，此时为(size+1)/2；（size为连续0的个数）
+ 然后是开头结尾是0的情况，此时为size/2；
+ 最后是连续0不在开头结尾处，(size-1)/2；

代码如下：

~~~c
bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
	int count = 0;
	int numsOf0 = 0;
	int size = flowerbed.size();
	for (int i = 0; i < size; i++)
	{
		if (flowerbed[i] == 1)//当遇到1时
		{
			if (numsOf0 == i )//开头为0
			{
				if (numsOf0 / 2 > 0)
					count += numsOf0 / 2;
			}
			else if ((numsOf0 - 1) / 2 > 0)//不是从开头连续的0
			{
				count += (numsOf0 - 1) / 2;
			}			
			numsOf0 = 0;
		}
		else if (i == size - 1)//遍历结束，且最后为0
		{
			numsOf0++;
			if (numsOf0 == size)//全为0
				count += (numsOf0 + 1) / 2;
			else//最后一位为0
				count += numsOf0 / 2;
		}
		else//没有遍历结束且没有遇到1
		{
			numsOf0++;
		}
	}	
	if (count >= n)
		return true;
	else
		return false;
}
~~~

下面这个解法里面的if逻辑判断写的很好，可以参考学习一下

~~~c
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
 
    int i;
    for(i = 0;i < flowerbedSize;++i)
    {
        if(flowerbed[i] == 1) continue;
        if((i == 0 || !flowerbed[i-1]) && (i == flowerbedSize - 1 || !flowerbed[i+1])) 
        {
            if(--n == 0)return true;
            flowerbed[i] = 1;
        }
    }
    return n <= 0;
}
~~~

