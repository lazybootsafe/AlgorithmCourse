# LeetCode 1436 |旅行终点站

+++

## 原题地址

<https://leetcode-cn.com/problems/destination-city/>



## 题意

给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。

题目数据保证线路图会形成一条不存在循环的线路，因此只会有一个旅行终点站。

 

示例 1：

~~~
输入：paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
输出："Sao Paulo" 
解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。本次旅行的路线是 "London" -> "New York" -> "Lima" -> "Sao Paulo" 。
~~~



示例 2：

~~~
输入：paths = [["B","C"],["D","B"],["C","A"]]
输出："A"
解释：所有可能的线路是：
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
显然，旅行终点站是 "A" 。
~~~



示例 3：

~~~
输入：paths = [["A","Z"]]
输出："Z"
~~~





## 题解

法一：

先将路径起点保存；然后遍历路径终点，和路径起点做比较；如果路径起点中没有找到路径终点，则即为最终终点返回

~~~c
char *destCity(char ***paths, int pathsSize, int *pathsColSize)
{
    int i, j;
    char **city = NULL;  // 存取起点城市
    int flag;            // 是否终点城市标记

    city = (char **)malloc(sizeof(char *) * pathsSize);
    if (city == NULL) {
        return NULL;
    }
    memset(city, 0, sizeof(char *) * pathsSize);
    for (i = 0; i < pathsSize; i++) {
        city[i] = malloc(sizeof(char) * 11);
        if (city[i] == NULL) {
            return NULL;
        }
        memset(city[i], 0 , sizeof(char) * 11);
    }

    for (i = 0; i < pathsSize; i++) {
        strcpy(city[i], paths[i][0]);
    }

    for (i = 0; i < pathsSize; i++) {
        flag = 0;
        for (j = 0; j < pathsSize; j++) {
            if (strcmp(paths[i][1], city[j]) == 0) {
                flag = 1; // 标记为1，表示在起点城市中可以找到
            }
        }
        if (flag == 0) {
            return paths[i][1];
        }
    }
    
    // 返回NULL，该句很重要，不然编译有误:control reaches end of non-void function
    return NULL;
}
~~~



法二：

其实是法一的优化，省去了对起点的保存
 遍历路径终点，和路径起点做比较；如果路径起点中没有找到路径终点，则即为最终终点返回

~~~c
char *destCity(char ***paths, int pathsSize, int *pathsColSize)
{
    int i, j;
    int flag;            // 是否终点城市标记

    for (i = 0; i < pathsSize; i++) {
        flag = 0;
        for (j = 0; j < pathsSize; j++) {
            if (strcmp(paths[i][1], paths[j][0]) == 0) {
                flag = 1; // 标记为1，表示在起点城市中可以找到
            }
        }
        if (flag == 0) {
            return paths[i][1];
        }
    }
    
    // 返回NULL，该句很重要，不然编译有误:control reaches end of non-void function
    return NULL;
}
~~~

