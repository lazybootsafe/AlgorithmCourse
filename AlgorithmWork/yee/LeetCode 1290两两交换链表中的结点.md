# LeetCode 1290|两两交换链表中的结点

+++

## 原题地址

<https://leetcode-cn.com/problems/swap-nodes-in-pairs/>

## 题意

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

**示例:**

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```



## 题解

![image-20200729162216853](C:\Users\Yee\AppData\Roaming\Typora\typora-user-images\image-20200729162216853.png)

准备三个指针per，first，second，和一个伪头结点，per指针始终指向first的前一个。当需要交换的时候判断越界的时候直接判断per即可。在不越界的情况下更改first和second的指针指向。最后连接per和first，同时更新per的指针指向下一个first

代码如下：

~~~c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head){
  
    if (!head || !head->next)
        return head;
    struct ListNode *per = (struct ListNode *)malloc(sizeof(struct ListNode));
    per->next=head;
//记录下新的头结点
    struct ListNode *newhead = per;
    while(per->next && per->next->next)
    {
        struct ListNode *first = per->next;
        struct ListNode *second = first->next;
        first->next = second->next;//根据second的next指针寻找后续链表， 
        second->next = first;//然后改变second的next指针指向first。
        per->next = second;//将per前的链表连接到 完成交换的链表
        per = first;//更新per
    }
    return newhead->next;


}
~~~

