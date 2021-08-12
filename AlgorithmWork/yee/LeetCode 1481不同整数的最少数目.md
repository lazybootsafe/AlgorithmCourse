# LeetCode 1481|不同整数的最少数目

+++

## 原题地址

<https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/>



## 题意

给你一个整数数组 `arr` 和一个整数 `k` 。现需要从数组中恰好移除 `k` 个元素，请找出移除后数组中不同整数的最少数目。

我们来看样例：

```
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left
```



## 题解——两轮快速排序

读完题目，我们需要关注的有：
1、总共出现了多少个数字；
2、每个数字出现的次数；
3、我们不需要关注每个数字具体是多少。

第一步：
先对原始的数组进行排序，qsort
排序后计算这n个数字出现的次数a[0],a[1],...,a[n - 1]

第二步：
对次数数组a[n]进行升序排序

第三步：
计算结果。
满足a[0] + a[1] + ... + a[i] >= k的最小i
返回n - i ，相当于移除了出现次数最小的那部分数字

代码如下：

~~~C
#define MAX_ARR_LEN 100001

int comp(const void *a, const void *b) {
    int m = *(int*)a;
    int n = *(int*)b;

    if (m > n) {
        return 1;
    }

    if (m == n) {
        return 0;
    }

    return -1;
}

int findLeastNumOfUniqueInts(int* arr, int arrSize, int k){
    int a[MAX_ARR_LEN]= {0};
    int count = 0;
    int flag = 0;

    if ((arr == NULL) || (arrSize == 0)) {
        return 0;
    }

    // 原数组排序
    qsort(arr, arrSize, sizeof(int), comp);

    // 对排序后的数组遍历，计算数字重复次数
    int number = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == number) {
            a[count]++;
            continue;
        }

        count++;
        a[count]++;
        number = arr[i];
    }
    count++;

    if (k == 0) {
        return count;
    }

    int reserve = k;
    int result = count;
    // 对个数排序
    qsort(a, count, sizeof(int), comp);
    for (int i = 0; i < count; i++) {
        if (a[i] < reserve) {
            reserve -= a[i];
            result--;
        } else if (a[i] == reserve) {
            result--;
            break;
        } else {
            break;
        }
    }

    return result;
}
~~~

