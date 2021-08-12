# LeetCode 709  |  转换成小写字母

+++

## 原题地址

<https://leetcode-cn.com/problems/to-lower-case/>



## 题意

实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

 

示例 1：

~~~
输入: "Hello"
输出: "hello"
~~~

示例 2：

~~~
输入: "here"
输出: "here"
~~~





## 题解

学习使用isupper和tolower函数，提高程序可读性

> C语言isupper函数用于**判断字符是否为大写字母**（A-Z）
>
> 1、包含头文件
>
> ```cpp
> #include <ctype.h>
> ```

​			2、函数声明

> ```cpp
> int isupper(int c);
> ```
>
> 3、功能说明
>
> 判断参数c是否为大写字母，您可能会问：isupper函数的参数是int c，是整数，不是字符，在C语言中，字符就是整数，请补充学习一下基础知识。
>
> 返回值：0-不是大写字母，非0-是大写字母。
>
> 4、示例
>
> ```cpp
> 
> #include <stdio.h>
> 
> int main()
> {
>   printf("isupper('-')=%d\n",isupper('-'));
>   printf("isupper('0')=%d\n",isupper('0'));
>   printf("isupper('a')=%d\n",isupper('a'));
>   printf("isupper('A')=%d\n",isupper('A'));
> }
> ```



~~~c
char *toLowerCase(char *str)
{
    int len = strlen(str);
    if (len < 1) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        isupper(str[i]) ? str[i] = tolower(str[i]) : ' ';
    }
    return str;
}
~~~

