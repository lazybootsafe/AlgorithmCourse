# LeetCode 1046  |  最后一块石头的重量

+++

## 原题地址

<https://leetcode-cn.com/problems/last-stone-weight/>



## 题意

有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

 

示例：

~~~
输入：[2,7,4,1,8,1]
输出：1
解释：
先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。


提示：

1 <= stones.length <= 30
1 <= stones[i] <= 1000
~~~



## 题解

利用贪心算法：5个石头撞4次，6个石头撞5次。那么说N个石头撞N-1次。即便两个石头等重量也是默认删除两个石头，加入一个重量为0的石头。这样碰撞N-1次，每次都排序，最后的首元素一定为最后剩余的石头。这种方法还不用管石头个数奇数或偶数。

~~~c
int Cmp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}
int lastStoneWeight(int* stones, int stonesSize)
{
    int time = stonesSize - 1;
    int buf[30] = {0};
    memcpy(buf, stones, stonesSize * sizeof(int));
    while (time > 0) {
        qsort(buf, 30, sizeof(int), Cmp);
        buf[0] -= buf[1];
        buf[1] = 0;
        time--;
    }
    return buf[0];
}
~~~



