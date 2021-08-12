# LeetCode 451|根据字符出现频率排序

+++

## 原题地址

<https://leetcode-cn.com/problems/sort-characters-by-frequency/>



##  题意

给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:

~~~
输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
~~~



示例 2:

~~~
输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
~~~



## 题解

1.如果字符串长度是 2 以内，无需任何操作，直接返回就行；
2.对各字符出现次数进行计数(ascii 字符串最大为 128)；
3.使用快速排序 qsort 对 s 排序：

4.按字符出现次数从大到小排列，但如果次数相等，则按字符本身从小到大排列；
5.为了代码简洁，特意把 cmp 子函数嵌套在函数内部。

~~~c
char * frequencySort(char * s){
    int len = strlen(s);
    if (len <= 2)
        return s;
    int count[128] = {0}; //ascii字符串最大为128
    for (int i = 0; i < len; i++) {
        count[s[i]]++;
    }
    int cmp(const void *p1, const void *p2) {
        char c1 = *(char*)p1;
        char c2 = *(char*)p2;
        //按字符出现次数从大到小排列，但如果次数相等，则按字符本身的从小到大排列
        return count[c1] == count[c2] ?  c1 > c2 : count[c1] < count[c2]; 
    }
    qsort(s, len, sizeof(char), cmp);
    return s;
}
~~~

