# 剑指 Offer 16. 数值的整数次方

+++

## 题意

实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。



示例 1:

~~~
输入: 2.00000, 10
输出: 1024.00000
~~~

示例 2:

~~~
输入: 2.10000, 3
输出: 9.26100
~~~



## 题解

采用快速幂法，将x^n分n为奇数和偶数进行不同计算，可实现时间复杂度O(logn)的解法，同时由于在C语言将负整数转换为正整数时，可能会有溢出情况，**通过unsigned int m = (unsigned int)n转换排除溢出问题**。

~~~c
double myPow(double x, int n){
    double res;

    if(x == 0)
        return 0;

    unsigned int m = (unsigned int)n;
    if(n < 0)
    {
        m = -m;
        x = 1 / x;
    }

    res = 1;
    while(m)
    {
        if(m & 1)
            res *= x;
        x *= x;
        m >>= 1;
    }

    return res;
}
~~~





