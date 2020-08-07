# LeetCode 1518  |  换酒问题

+++

## 原题地址

<https://leetcode-cn.com/problems/water-bottles/>



## 题意

小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。

如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。

请你计算 最多 能喝到多少瓶酒。



**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/sample_1_1875.png)

~~~
输入：numBottles = 9, numExchange = 3
输出：13
解释：你可以用 3 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 9 + 3 + 1 = 13 瓶酒。
~~~

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/sample_2_1875.png)

~~~
输入：numBottles = 15, numExchange = 4
输出：19
解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 15 + 3 + 1 = 19 瓶酒。
~~~



## 题解

利用sum变量记录喝了多少瓶酒。
这道题主要是要理解两个状态，喝酒之前和喝酒之后：
喝酒前：sum主要的来源是空酒瓶兑换来的有酒的瓶子，即numBottles/numExchange,累加
喝酒之后：numBottles发生变化，主要来源是上一次喝完的numBottles/numExchange加上上一次没法兑换的空瓶子
递归求出最后的sum
边界条件：初始的时候sum=numBottles，结束条件是剩余空酒瓶不够兑换了

~~~c
int numWaterBottles(int numBottles, int numExchange){
   int sum=numBottles;
   while(numBottles>=numExchange){
     sum=sum+numBottles/numExchange;
     numBottles=numBottles/numExchange+numBottles%numExchange;
   }
   return sum;
}
~~~

