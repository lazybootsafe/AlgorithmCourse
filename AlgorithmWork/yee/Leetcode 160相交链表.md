# Leetcode 160|相交链表

+++

## 原题地址

<https://leetcode-cn.com/problems/intersection-of-two-linked-lists/>



## 题意

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)

在节点 c1 开始相交。



样例：

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_1.png)

~~~c
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
~~~



## 题解

**A,B各自长度未知，重点在于长度的处理**；

我们可以同时遍历两个链表，当其中一个链表遍历结束时再单独遍历另外一个链表余下部分，并用一个变量记录两个链表的长度差L。然后重新将这两个指针指向头结点，长链表先遍历L个结点，然后两个链表同时遍历，直至两个指针相等。若有相交会返回相交结点，若无相交会返回NULL。

代码如下：

~~~c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int dif_length = 0;
    int flag = 0;
    struct ListNode *pa = headA;
    struct ListNode *pb = headB;
    
    if (!headA || !headB)
        return NULL;
    
    while (pa && pb)
    {
       pa = pa->next;
       pb = pb->next; 
    }
    
    if (!pa)    //B比A长
    {
        while (pb)
        {
            pb = pb->next; 
            dif_length++;
        }
        flag = 0;
    }
    else       //A比B长
    {
        while (pa)
        {
            pa = pa->next; 
            dif_length++;
        }
        flag = 1;
    }
    
    pa = headA;
    pb = headB;
    
    if (!flag) //B比A长
    {
        while (dif_length--)
        {
            pb = pb->next; 
        }
        while (pb != pa)
        {
            pa = pa->next; 
            pb = pb->next;
        }
        return pa;
    }
    else
    {
         while (dif_length--)
        {
            pa = pa->next; 
        }
        while (pb != pa)
        {
            pa = pa->next; 
            pb = pb->next;
        }
        return pa;
    }
    
}
~~~

