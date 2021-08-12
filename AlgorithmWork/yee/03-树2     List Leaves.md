# 03-树2     List Leaves

+++

## 题意

给定一棵树，你应该按照从上到下，从左到右的顺序列出所有的叶结点。

### 输入规格：

每个输入文件包含一个测试用例。对于每种情况，第一行给出一个正整数N（≤10），这是树中节点的总数——因此节点的编号从0到N−1。接下来是N行，每行对应一个节点，并给出该节点左、右子节点的索引。如果子项不存在，则在该位置加一个“-”。任何一对孩子都被一个空格隔开。

### 输出规格：

对于每个测试用例，在一行中按从上到下、从左到右的顺序打印所有叶节点的索引。任何相邻的数字之间必须有一个空格，行尾不能有多余的空格。

### Sample Input:

```in
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
```

### Sample Output:

```out
4 1 5
```



## 题解

**这道题跟上道题二叉树的构建类似，不同的是这个题节点的数据就是它在数组中的下标，很明显必须采用层次遍历的方式才能从上到下从左到右输出叶子节点。这里采用队列的方式实现层次遍历。**

~~~c++
#include<cstdio>
#include<cstdlib>
#inclulde<iosteam>
#include<queue>
using namespace std;
#define maxtree 10
#define null -1
#define Tree int 

struct treenode
{
    Tree left;
    Tree right;
}T[maxtree];

int N,check[maxteee]={0},count=0;
queue<int> q;

Tree buildtree(struct treenode T[])
{
    Tree root=null;
    int i;
    char cl,cr;
    scanf("%d",&N);
    if(N)
    {
        for(i=0;i<N;i++)
        {
            scanf("%c %c\n",&cl,&cr);
        if(cl!='-'){
                T[i].left=cl-'0';
                check[T[i].left]=1;
            }
         else T[i].left=null;
        
        if(cr!='-'){
                T[i].right=cr-'0';
                check[T[i].right]=1;
            }
            else T[i].right=null;
   		}    
     for(i=0;i<N;i++)
            if(check[i]==0) break;
        root=i;
    }
    return root;
}

//每碰到一个节点将它的左右孩子入队（若有的话），然后依次从队头取出并判断是否为叶节点
//层序遍历
void countleaves(Tree root)
{
    Tree temp;
    if(root==NULL)
        return;
    q.push(root);//往队列中加入元素root
    while(!q.empty())
    {
        temp=q.front();//front()访问队首元素
        q.pop();//pop() 删除队顶元素
        if(T[temp].left==null&&T[temp].right==null)//如果没有左右孩子即为叶节点，则输出
        {
            if(count++!=0)//不是第一个节点的话前面要输出空格
                putchar('');
            
             printf("%d",temp);
        }
        if(T[temp].left!=null)     		 					q.push(T[temp].left);
        if(T[temp].right!=null)     						q.push(T[temp].right); 
       
    }
    
}

int main()
{
    Tree r;
    r=buildtree(T);
    countleaves(r);
    return 0;
}
~~~



# 			 拓展：STL中队列（queue）的使用方法  

## queue是什么?

queue是一种先入先出的容器



## queue的定义

### 引入

```cpp
# include <iostream>
# include <queue>
using namespace std;
```

### 定义

```cpp
普通声明：
    queue<int> q;

结构体：
struct node
{    
   int x, y;
};
queue<node> q;
```



## 基本操作

~~~
push(x) 将x压入队列的末端

pop() 弹出队列的第一个元素(队顶元素)，注意此函数并不返回任何值

front() 返回第一个元素(队顶元素)

back() 返回最后被压入的元素(队尾元素)

empty() 当队列为空时，返回true

size() 返回队列的长度
~~~



## queue元素的访问

**STL只能通过front()访问队首元素，或者使用back()访问队尾元素**

```cpp
queue<int> q;
for(int i=0;i<5;i++)
{
    q.push(i);
}
cout<<q.front()<<' '<<q.back()<<endl;
```



## queue中的实用函数

### front()和back()

获取容器队首和队尾元素

### pop()队首元素出队

```cpp
queue<int> q;
for(int i=0;i<5;i++)
{
    q.push(i);
}
for(int i=0;i<3;i++)
{
    q.pop();
}
cout<<q.front()<<endl;//3
```

### empty()

判断是否为队列是否为空，如果空返回true,否则返回false

### size()

返回容器元素数量

```cpp
queue<int> q;
for(int i=0;i<5;i++)
{
    q.push(i);
}
cout<<q.size()<<endl;//5
```



## queue的用途以及注意事项

- 广度优先搜索
- **在使用pop()之前，一定要使用empty()判断是否为空**