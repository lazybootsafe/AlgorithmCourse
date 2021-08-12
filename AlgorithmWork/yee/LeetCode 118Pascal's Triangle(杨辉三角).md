# LeetCode 118|Pascal's Triangle(杨辉三角)

## 原题地址

<https://leetcode.com/problems/pascals-triangle/>

本题官方难度Easy，通过率大约52%。当我们想到用循环解决这个问题的时候，同时也到注意对称性的应用。

## 题意

给定一个非负整数 *numRows，*生成杨辉三角的前 *numRows* 行。

样例如下：

~~~
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

~~~

## 题解

将Pascal‘s Triangle看成是下三角(如下所示),通过二重循环对二维数组进行赋值。Pascal’s Triangle具有对称性，在处理时应加以利用。

> [
>
> [1],
>
> [1,1],
>
> [1,2,1],
>
> [1,3,3,1],
>
> [1,4,6,4,1]
>
> ]

代码如下：

~~~c

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    //定义返回数组
    int** returned = (int**)malloc(sizeof(int*)*numRows);
    //定义返回数组每行的列数
    *returnColumnSizes = (int*)malloc(sizeof(int)*numRows);
    
    int i=0,j;
    
    while(i<numRows){//按行处理
        
        returned[i] = (int*)malloc(sizeof(int)*(i+1));//给每行分配空间
        //第i行有i列，下面i是下标，所以加1
        (*returnColumnSizes)[i]=i+1;
        //每行首尾初始化为1
        returned[i][0]=returned[i][i]=1;
        
        j=1;
        while(j<=i/2){//按列处理，对称原则只需处理i/2列
            
            returned[i][j]=returned[i-1][j-1]+returned[i-1][j];
            returned[i][i-j]=returned[i][j];//利用前后对称性质，直接赋值
            //returned[i][i-j]=returned[i][j];或者
            //或者returned[i][i-j]=returned[i-1][i-j]+returned[i-1][i-j-1];两者都可
            j++;
        }
        i++;
    }
    
    *returnSize = numRows;
     return returned;
    
}
~~~

## 题后反思

+ 要有将杨辉三角看成是下三角的思想。
+ 对int** returned(返回数组)和*returnColumnSizes(返回列个数数组)两个数组的空间分配要清楚。
+ 了解int* returnSize要使用时总是*returnSize，不然会出错。
+ 利用好对称性，可以简化算法。如：returned[i][i-j]=returned[i][j];//利用前后对称性质，直接赋值
  