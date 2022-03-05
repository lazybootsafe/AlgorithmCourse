# LeetCode 779  |  第K个语法符号

+++

## 原题地址

<https://leetcode-cn.com/problems/k-th-symbol-in-grammar/>



## 题意

在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）


例子:

~~~
输入: N = 1, K = 1
输出: 0

输入: N = 2, K = 1
输出: 0

输入: N = 2, K = 2
输出: 1

输入: N = 4, K = 5
输出: 1

解释:
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001
~~~



## 题解

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200228220740904.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTIzNDAwMQ==,size_16,color_FFFFFF,t_70)

通过上图分析，可以得到其实第N行的第K个数字，可以从第N-1行的第(K-1)/2+1个数字产生
 因此可以采用递归的方法进行处理

~~~c
//公式法
//通过找规律可以发现
//第n行的第k个等于第n-1行的第(k-1)/2+1个数产生
//第n-1行的第(k-1)/2+1个数可能为0，可能为1，所以要分两种情况
//判断第n行中的第k个数字，属于奇数还是偶数，奇数选择第一个数字，偶数选择第二个数字（通过%号来选择）
class Solution {
public:
	int kthGrammar(int N, int K) {
		if (N == 1) return 0;
		return kthGrammar(N - 1, (K - 1) / 2 + 1) == 0 ? (K - 1) % 2 : 1 - (K - 1) % 2;
	}
};
~~~

