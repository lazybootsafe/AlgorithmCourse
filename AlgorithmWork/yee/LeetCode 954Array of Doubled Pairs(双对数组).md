# LeetCode 954|Array of Doubled Pairs(双对数组)

## 原题地址

<https://leetcode.com/problems/array-of-doubled-pairs/>

本题的官方难度是Medium，通过率大约36%，我看评论区解答用到了三种方法，我是没有想出来的，对我来说还是有点难度的。

## 题意

给定一个长度为偶数的整数数组 A，只有对 A 进行重组后可以满足 “对于每个 0 <= i < len(A) / 2，都有 A[2 * i + 1] = 2 * A[2 * i]” 时，返回 true；否则，返回 false。

我们来看样例：

```
Input: [3,1,3,6]
Output: false

Input: [2,1,2,6]
Output: false
```

## 题解

会用到排序，拆分数组，分别统计这三种方法；

由于取值范围100000以内，声明一个100000大小的数组，然后排序，利用X能找到，2X也必定存在的关系进行统计；
最后能统计的到等于总数，说明满足条件，否则说明存在不成对的；
1、先将数组按照大小升序排序
2、由于存在负数，将数组拆分为负数数组合正数数组分别处理；
3、负数数组：-4若存在，则-2也必定存在；进行标记并统计；
4、正数数组：2若存在，则4也必定存在；进行标记并统计；
5、等于总和则说明找到所有对；不等于说明没找到所有对；

代码如下：

~~~c

#define MAX_NUM  30000
#define MAX_VALUE 100000

int cmpup(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool canReorderDoubled(int* A, int ASize)
{
    int i;
    int j;
    int count = 0;

    int Pos[MAX_NUM] = { 0 }; // 正
    int PosNum = 0;
    int PosCount[MAX_VALUE] = {0};
    int Neg[MAX_NUM] = {0}; // 负
    int NegNum = 0;
    int NegCount[MAX_VALUE] = {0};
    int value = 0;

    // 先排序
    qsort(A, ASize, sizeof(int), cmpup);

    // 分成负数数组和正数数组
    for (i = 0; i < ASize; i++) {
        if (A[i] < 0) {
            value = -1 * A[i];
            Neg[NegNum++] = value;
            NegCount[value]++;
        } else {
            value = A[i];
            Pos[PosNum++] = value;
            PosCount[value]++;
        }
    }

    // 负数数组处理, -4存在时，-2也同时必定存在，同时统计个数+2
    for(i = 0; i < NegNum; i++) {
        value = Neg[i];
        if (NegCount[value] != 0) {
            NegCount[value]--;
            NegCount[value/2]--;
            count += 2;
        }
    }

    // 正数数组处理,2存在时，4也同时必定存在，同时统计个数+2
    for(i = 0; i < PosNum; i++) {
        value = Pos[i];
        if (PosCount[value] != 0) {
            PosCount[value]--;
            PosCount[2*value]--;
            count += 2;
        }
    }

    // 统计到所有，说明满足条件，否则不满足
    if (count == ASize) {
        return true;
    } else {
        return false;
    }
}
~~~

