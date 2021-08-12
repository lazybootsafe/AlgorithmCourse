# LeetCode 1387|将整数按权重排序

+++

## 原题地址

<https://leetcode-cn.com/problems/sort-integers-by-the-power-value/>



## 题意

我们将整数 x 的 权重 定义为按照下述规则将 x 变成 1 所需要的步数：

    如果 x 是偶数，那么 x = x / 2
    如果 x 是奇数，那么 x = 3 * x + 1

比方说，x=3 的权重为 7 。因为 3 需要 7 步变成 1 （3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）。

给你三个整数 lo， hi 和 k 。你的任务是将区间 [lo, hi] 之间的整数按照它们的权重 升序排序 ，如果大于等于 2 个整数有 相同 的权重，那么按照数字自身的数值 升序排序 。

请你返回区间 [lo, hi] 之间的整数按权重排序后的第 k 个数。

注意，题目保证对于任意整数 x （lo <= x <= hi） ，它变成 1 所需要的步数是一个 32 位有符号整数。

示例 1：

~~~
输入：lo = 12, hi = 15, k = 2
输出：13
解释：12 的权重为 9（12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）
13 的权重为 9
14 的权重为 17
15 的权重为 17
区间内的数按权重排序以后的结果为 [12,13,14,15] 。对于 k = 2 ，答案是第二个整数也就是 13 。
注意，12 和 13 有相同的权重，所以我们按照它们本身升序排序。14 和 15 同理。
~~~



示例 2：

~~~
输入：lo = 1, hi = 1, k = 1
输出：1
~~~



## 题解

借鉴大佬的思路

很多人都在研究怎么优化计算权重的问题，但是却很少研究算完权重之后找第K个的问题
几乎都是直接排序，其实没有必要排序。
思路如下，list_point数组的下标对应权重step，所以算完权重之后直接去list_point[step]里面找到对应的list
list中的head指向的是第一个权重为step的数，也是最小的数，pos指向最后一个权重为step的数
src_num的下标就是是1~1000的数，里面的内容指向下一个相同权重的数。
例如假设2，4，6的权重都是2，那么整个结构如下图：

![image.png](https://pic.leetcode-cn.com/337799f5ea2e40545639995d02e18a81ac3abee592aedf4d70aaba8b37440b8d-image.png)

最后根据list中记录的size可以知道第K个落在哪个list中，再根据list的head一个一个往后找就行了

~~~c
typedef struct {
	unsigned short head;
	unsigned short pos;
	unsigned short size;
} LIST;
unsigned int get_step_num(unsigned int num)
{
	unsigned int step = 0;
	while (num != 1) {
		if (num & 0x01) {
			num = num * 3 + 1;
		}
		else {
			num = num >> 1;
		}
		step++;
	}
	return step;
}
int getKth(int lo, int hi, int k) {
	int i = 0, tail = 0, num;
	unsigned int step = 0;
	int src_num[1001];
	int list_point[179];//最大权重为178
	LIST list[179];//最大权重为178
	memset(list_point, 0xFF, sizeof(list_point));

	for (i = lo; i <= hi; i++) {
		step = get_step_num(i);
		if (list_point[step] == 0xFFFFFFFF) {
			list_point[step] = tail;
			list[tail].head = i;
			list[tail].pos = i;
			list[tail].size = 1;
			tail++;
		}
		else {
			list[list_point[step]].size++;
			src_num[list[list_point[step]].pos] = i;
			list[list_point[step]].pos = i;
		}
	}
	i = 0;
	step = 0;
	while (1) {
		if (list_point[step] == 0xFFFFFFFF) {
			step++;
			continue;
		}
		if (i + list[list_point[step]].size >= k)break;
		i += list[list_point[step]].size;
		step++;
	}
	i = k - i - 1;
	num = list[list_point[step]].head;
	while (i > 0) {
		num = src_num[num];
		i--;
	}
	return num;
}
~~~

