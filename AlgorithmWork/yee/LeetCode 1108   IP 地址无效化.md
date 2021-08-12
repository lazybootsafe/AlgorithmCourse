# LeetCode 1108 |  IP 地址无效化

+++

## 原题地址

<https://leetcode-cn.com/problems/defanging-an-ip-address/>



## 题意

给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

 

示例 1：

~~~
输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
~~~

示例 2：

~~~
输入：address = "255.100.50.0"
输出："255[.]100[.]50[.]0"
~~~



## 题解

本题主要是回顾字符串的结束符'\0'的用法。

'\0'一般放在**字符串的结束处**，表示**字符串的结束**，其是ascii值为0的字符的转义。
在头文件#include <string.h>中包含的一些字符串处理函数等中，一般处理字符串时，**都是一'\0'作为字符串的结束**，**如果一个字符串中没有'\0'这个结束字符，那么这些函数将不能确定字符串的结束位置在哪儿，从而引起一些不必要的错误。**

~~~c

char * defangIPaddr(char * address){
    int len=strlen(address);
    int i=0,j=0;
    char *an=(char*)malloc(sizeof(char)*(len+10));//进行重新存储后数组
    for(i=0;i<len;i++)//分别加入“[.]”
    {
        if(address[i]=='.')
        {
            an[j++]='[';
            an[j++]='.';
            an[j++]=']';
            continue;
        }
        an[j++]=address[i];
    }
    an[j]='\0';//‘\0’表示字符串结束
    return an;
}

~~~

