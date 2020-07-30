# LeetCode 19|删除链表的倒数第N个节点

+++

## 原题地址

<https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/>



## 题意

给定一个链表，删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

## 题解

可使用双指针进行求解，同时需注意对NULL值进行处理。

![https://img2018.cnblogs.com/blog/1741670/201908/1741670-20190805084549278-1922824400.jpg](https://img2018.cnblogs.com/blog/1741670/201908/1741670-20190805084549278-1922824400.jpg)

(1) 建立两个指针，同时指向头结点；
 (2) first向后走n步，假设n = 2，所以first由(1)中位置移动到(2)中位置；
 (3) first和second同时向后走，当first走到末尾时终止；
 (4) 将second指向second的next的next。

~~~c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL || n == 0)
        return head;
    struct ListNode *first, *second;
    first = head;
    second = head;
    while(n--)
        first = first->next;
    if(first == NULL)
        return head->next;
    while(first->next)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return head;
    
}
~~~

