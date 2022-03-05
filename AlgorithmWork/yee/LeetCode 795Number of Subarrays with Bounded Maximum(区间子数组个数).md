# LeetCode 795|Number of Subarrays with Bounded Maximum(区间子数组个数)

## 原题地址

<https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/>

## 题意

给定一个元素都是正整数的数组`A` ，正整数 `L` 以及 `R` (`L <= R`)。

求连续、非空且其中最大元素满足大于等于`L` 小于等于`R`的子数组个数

我们来看样例：

```

Input: 
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
```



## 题解

基本思路就是从左往右遍历数组，统计每个元素可能作为子数组结尾的可能性数量。

这么说不好理解，直接举一个例子：

~~~
A = [0, 0, 1, 1, 0, 0, 2, 0]
L = 1, R = 1    // 只有 1 是符合最大值要求的
~~~

此时我们看A[2]，也就是第一个 1，全部可能以A[2]为结尾的满足题意的子数组只有三个：[1]、[0, 1]和[0, 0, 1]，所以这里它带来了三种新可能性。

因此从左向右遍历，只要每次计算出以当前元素结尾的合法子数组数目就行，而且“以此结尾”保证了从左往右遍历是不会多加也不会漏加任何可能性的。

> 通过题意，不难看出任意数字都只能被分为三种类型：位于LR之间的合法最大值（x >= L && x <= R），大于R的值（x > R，这种数不可能在子数组里），小于L的值（x < L）。
>
> 为了方便说明算法，给上面三种分别起一个代号：1、2、0。（也就是上面例子里的）
>
> 在遍历过程中，只需要维护两个状态：lastInvalid和lastMid，代表两种数字上次出现的位置。
>
> + ***如果是 1:***
>
>   那么从lastInvalid之后到它本身之间，都可以作为一个子数组的“头”，自己作为“尾”，可能性有index - lastInvalid种。
>
>   因为这保证了其中肯定不存在 2，也有自己这个 1作为合法最大值撑门面（就算有别的 1比它大也不影响，不是 2就行）。此时更新lastMid=index。
>
>   举例的话，刚开始的例子就ok。[1]、[0, 1]和[0, 0, 1]。
>
>   
>
> + ***如果是 2：***
>
> 这种大于 R的数字相当于一座不可逾越的山，不可能出现在子数组里，子数组的“头”和“尾”也不可能跨越它的两边构成子数组。可能性为0种。
>
> 因此此时设置 lastInvalid = index, lastMid = -1，没有加入任何可能性。lastMid为什么要置为 -1接下来说。
> 
>
> + ***如果是 0：***
>
> 这种数字自己不可能单独构成子数组，缺乏 LR之间的合法最大值撑门面。因此，lastMid状态就派上用场了，lastMid位置作为“尾”的子数组，都可以延长到当前位置，成为一个新的合法子数组。可能性有lastMid - lastInvalid种。（如果lastMid == -1那就不存在，pass）
>
> 之所以可以这么延长，是因为保证了当前位置和lastMid之间的只有 0，如果有 1或 2的话，当时 lastMid都会置成 -1或当时的 index。
>
> 举例：
>
> A = [0, 0, 1, 1, 0, 0, 2, 0]里的第 4个 0，A[5]，可能以它为尾的子数组数目和“以A[3]为尾的子数组数目”是一致的。
>
>     [1] -> [1, 0, 0]
>     [1, 1] -> [1, 1, 0, 0]
>     [0, 1, 1] -> [0, 1, 1, 0, 0]
>     [0, 0, 1, 1] -> [0, 0, 1, 1, 0, 0]
>
> lastMid == 3, lastInvalid == -1
>
> 

代码如下：

~~~C
int numSubarrayBoundedMax(int* A, int ASize, int L, int R){
    int lastInvalid = -1, lastMid = -1, sum = 0, index = 0;
    while (index < ASize) {
        int val = (A[index]);
        if (val > R) { lastInvalid = index; lastMid = -1; }
        else if (val < L) {
            if (lastMid != -1) {
                sum += (lastMid - lastInvalid);
            }
        }
        else { sum += (index - lastInvalid); lastMid = index; }
        index ++;
    }
    return sum;
}

~~~

