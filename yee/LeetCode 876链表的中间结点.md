# LeetCode 876|链表的中间结点

+++

## 原题地址

<https://leetcode-cn.com/problems/middle-of-the-linked-list/>

## 题意

给定一个带有头结点 `head` 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

 示例 1：

~~~
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
~~~



## 题解

定义两个指针p,q。其中p每次循环后移两次，q每次循环后移一次。这样当p遍历完链表后，q指针刚好指向链表中央。
当结点个数为奇数，直接输出q指针指向结点的地址。
当结点个数为偶数，按题意输出q指针指向的结点的下一个结点的地址。

~~~c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* p;
    struct ListNode* q;
    p = q = head;
    while(1)
    {
        if(p->next == NULL)
        {
            break;
        }
        else if(p->next->next == NULL)
        {
            q = q -> next;
            break;
        }
        else
        {
            p = p->next ->next;
            q = q->next;
        }
    }
    return q;
}
~~~

