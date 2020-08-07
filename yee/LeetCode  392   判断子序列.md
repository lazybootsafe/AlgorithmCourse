# LeetCode  392 |  判断子序列

+++

## 原题地址

<https://leetcode-cn.com/problems/is-subsequence/>



## 题意

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

示例 1:

~~~
s = "abc", t = "ahbgdc"

返回 true.
~~~

示例 2:

~~~
s = "axc", t = "ahbgdc"

返回 false.
~~~





## 题解

双指针一次遍历：

双指针同时遍历s和t, 相等时, 指针右移; 不等时, 只右移t的指针. 结束时, 如果s还没遍历完, 说明s中还有元素在t中没找到, 也就是s不是t的子序列

~~~c

bool isSubsequence(char * s, char * t){
    if(!s) return true;
    if(!t) return false;

    while(*s != '\0' && *t != '\0')
    {
        if(*s == *t)
        {
            s ++;
            t ++;
        }
        else
        {
            t ++;
        }
    }

    if(*s != '\0')
        return false;
    
    return true;
}
~~~

