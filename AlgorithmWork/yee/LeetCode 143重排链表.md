# LeetCode 143|重排链表

+++

## 原题地址

<https://leetcode-cn.com/problems/reorder-list/>



## 题意

给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

（你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。）

示例 1:

~~~
给定链表 1->2->3->4, 重新排列为 1->4->2->3.
~~~

示例 2:

~~~
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
~~~



## 题解

1、算法说明：
算法分为三步，举例说明：
链表：1 -> 2 -> 3 -> 4 -> 5 -> 6

第一步，将链表平均分成两半：
1 -> 2 -> 3
4 -> 5 -> 6
第二步，将第二个链表逆序（反转）：
1 -> 2 -> 3
6 -> 5 -> 4
第三步，依次连接两个链表：
1 -> 6 -> 2 -> 5 -> 3 -> 4

~~~c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//反转链表
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode* pstLnTemp = NULL;
    struct ListNode* pstLnCur = NULL;
    struct ListNode* pstLnPre = NULL;

    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    while(NULL != pstLnCur)
    {
        pstLnTemp = pstLnCur->next;
        pstLnCur->next = pstLnPre;
        pstLnPre = pstLnCur;
        pstLnCur = pstLnTemp;
    }

    return pstLnPre;
}

void reorderList(struct ListNode* head){
    struct ListNode* pstLnFast = NULL;
    struct ListNode* pstLnSlow = NULL;
    int iLength = 0;
    struct ListNode stLnHead = {0};
    struct ListNode* pstLnPre = NULL;

    if(NULL == head)
    {
        return head;
    }

    //1.快慢指针将链表平均分成两半。
    pstLnFast = head;
    pstLnSlow = head;
    while((NULL != pstLnFast) && (NULL != pstLnFast->next))
    {
        pstLnSlow = pstLnSlow->next;
        pstLnFast = pstLnFast->next->next;
        iLength++;
    }

    //2.将第二个链表逆序（反转）。
    pstLnSlow = reverseList(pstLnSlow);
    pstLnFast = head;

    //3.利用哨兵节点依次连接两个链表。
    pstLnPre = &stLnHead;
    while(iLength>0)
    {
        pstLnPre->next = pstLnFast;
        pstLnFast = pstLnFast->next;
        pstLnPre = pstLnPre->next;

        pstLnPre->next = pstLnSlow;
        pstLnSlow = pstLnSlow->next;
        pstLnPre = pstLnPre->next;

        iLength--;
    }

    //3.连接两个链表的另一种实现方法。
    /* while(NULL != pstLnFast)
    {
        pstLnTemp = pstLnFast->next;
        pstLnFast->next = pstLnSlow;
        pstLnFast = pstLnSlow;
        pstLnSlow = pstLnTemp;
    } */

}

  
~~~

