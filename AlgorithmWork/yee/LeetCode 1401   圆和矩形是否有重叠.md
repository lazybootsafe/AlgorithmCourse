# LeetCode 1401 |  圆和矩形是否有重叠

+++

## 原题地址

<https://leetcode-cn.com/problems/circle-and-rectangle-overlapping/>



## 题意

给你一个以 (radius, x_center, y_center) 表示的圆和一个与坐标轴平行的矩形 (x1, y1, x2, y2)，其中 (x1, y1) 是矩形左下角的坐标，(x2, y2) 是右上角的坐标。

如果圆和矩形有重叠的部分，请你返回 True ，否则返回 False 。

换句话说，请你检测是否 存在 点 (xi, yi) ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_4_1728.png)

~~~
输入：radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
输出：true
解释：圆和矩形有公共点 (1,0) 
~~~

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_2_1728.png)

~~~
输入：radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
输出：true
~~~

示例 3：

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_6_1728.png)

~~~
输入：radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
输出：true
~~~



## 题解

### 方法一：暴力+常规解法

**遍历矩形的所有点，与圆心位置进行判断，若任意两点距离小于等于半径就返回 `true` 就行了，否则返回 `false` 就行了。**

暴力法就是这么的无脑，我一开始以为这是一个平面上的无穷多点，而非有限的整数点，所以首先就排除了暴力法，画图画有思路但一直卡样例，真是无语了，但是暴力法也是很多缺陷，若数据量一大，一定.....

参见代码如下：

~~~cpp
class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r) return true;
            }
        }
        return false;
    }
};
~~~



### 方法二：数学+巧妙解法

很简单的一道计算几何的问题。借用一下题解区大佬的图片。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200405225216989.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3lsX3B1eXU=,size_16,color_FFFFFF,t_70#pic_center)

就分别判段这三种情况就行了。很巧妙的解法。在这里要注意，`C++` 多个数字用 `min` 函数进行求 `min` 时，需要加上大括号，否则产生歧义。

~~~cpp
class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        // 圆心在矩形内部
        if (x >= x1 and x <= x2 and y >= y1 and y <= y2) return true;
        //圆在正方形的 左 右 上 下 时的相交条件
        if ((y >= y1 and y <= y2 and x < x1 and x1 - x <= r) or 
            (y >= y1 and y <= y2 and x > x2 and x - x2 <= r) or 
            (x >= x1 and x <= x2 and y > y2 and y - y2 <= r) or 
            (x >= x1 and (x <= x2 and y < y1 and y1 - y <= r))) return true;
        return min({(x1 - x) * (x1 - x) + (y2 - y) * (y2 - y), (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y), 
                   (x2 - x) * (x2 - x) + (y1 - y) * (y1 - y), (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)}) <= r * r;
    }
};
~~~



### 方法三：数学+向量+坐标变换+顶级解法

也是在[**题解区学到的解法**](https://leetcode-cn.com/problems/circle-and-rectangle-overlapping/solution/yi-pian-zhi-hu-gao-zan-hui-da-shi-yong-shu-xue-fan/)，来自知乎大佬 `Milo Yip` 在知乎的分享

> 大佬 `Milo Yip` 在知乎的分享：
>
> 设**c**为矩形中心，**h**为矩形半長，**p**为圆心，r为半径。
>
> ![img](https://pic1.zhimg.com/80/9230a91992b72b999a0e4fe3bb2f9195_720w.jpg?source=1940ef5c)
>
> 方法是计算圆心与矩形的最短距离 **u**，若 **u** 的长度小于 *r* 则两者相交。
>
> **1.**     首先利用绝对值把 **p** - **c** 转移到第一象限，下图显示不同象限的圆心也能映射至第一象限，这不影响相交测试的结果：
>
> ![img](https://pic2.zhimg.com/80/31fcf0a6ba5b5b925d7d82dc5bc8a684_720w.jpg?source=1940ef5c)
>
> **2.**    然后，把 **v** 减去 **h**，负数的分量设置为0，就得到圆心与矩形最短距离的矢量 **u**。下图展示了4种情况，红色的**u**是结果。
>
> ![img](https://pic4.zhimg.com/80/60b09b89d9b4eda3fe9bdb849ec5d5d1_720w.jpg?source=1940ef5c)
>
> **3.**   最后要比较 **u** 和 *r* 的长度，若距离少于 *r*，则两者相交。可以只求 **u** 的长度平方是否小于 *r* 的平方。
>
> 代码：
>
> ~~~c
> bool BoxCirleIntersect(Vector2 c, Vector2 h, Vector2 p, float r)
> {
>    Vector2 v = abs(p - c);    // 第1步：转换至第1象限
>    Vector2 u = max(v - h, 0); // 第2步：求圆心至矩形的最短距离矢量
>     return dot(u, u) <= r * r; // 第3步：长度平方与半径平方比较
> }
> ~~~
>
> 

这个方法具有很强的拓展性。

参见代码如下：

~~~cpp
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // (tx,ty)表示未变换之前的矩形中心
        int tx = (x1 + x2) / 2, ty = (y1 + y2) / 2; 
        // (tdx,tdy)表示变换之后的矩形中心
        int tdx = -tx, tdy = -ty; 
        // (x11,y11),(x21,y21)表示矩形的左下和右上端点
        int x11 = x1 + tdx, x21 = x2 + tdx, y11 = y1 + tdy, y21 = y2 + tdy;
        // (xc,yc)表示变换到第一象限的圆心坐标 
        int xc = abs(x_center + tdx), yc = abs(y_center + tdy); 
        // (ux,uy)表示u向量
        int ux = xc - x21, uy = yc - y21;
        // 将u向量中的x,y小于0的置为0
        ux = max(0, ux), uy = max(0, uy);
        // 判断
        return ux * ux + uy * uy <= radius * radius;  
    }
};
~~~

