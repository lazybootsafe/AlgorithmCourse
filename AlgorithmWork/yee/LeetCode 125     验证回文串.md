# LeetCode 125  |   验证回文串

+++

## 原题地址

<https://leetcode-cn.com/problems/valid-palindrome/>



## 题意

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

~~~
输入: "A man, a plan, a canal: Panama"
输出: true
~~~

示例 2:

~~~
输入: "race a car"
输出: false
~~~



## 题解

C语言知识点

C语言  strlen()  tolower()  toupper()

> toupper()将字bai符du转换为大写zhi英文字母
>
> tolower()把字符转换成小写bai字母

char c[]="aBc";

int len = strlen(c); // len长为3

tolower(c); //  "aBc" 变成 "abc"

toupper(c); //  "aBc" 变成 "ABC"



~~~c
bool isPalindrome(char* s) {
    int i,k=0,len =strlen(s);
    char *ss = (char *)malloc(sizeof(char)*len);
    //拼接一个只有小写字母和数字的字符串
    for(i=0;i<len;i++) {
        if((s[i]>='0' && s[i]<='9') || (tolower(s[i])>='a' && tolower(s[i])<='z' )) {
            ss[k++]=tolower(s[i]);
        }
    }
    //判断是否回文
    for(i=0;i<k/2;i++) {
        if(ss[i]!=ss[k-i-1]) {
            return false;
        }
    }
    return true;
}
~~~



