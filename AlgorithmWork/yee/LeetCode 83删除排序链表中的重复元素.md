# LeetCode 83|删除排序链表中的重复元素

+++

## 原题地址

<https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/>



## 题意

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 :

~~~
输入: 1->1->2
输出: 1->2

输入: 1->1->2->3->3
输出: 1->2->3
~~~



## 题解

这道题用一个指针就可以解决，没有必要使用两个指针，那样会不但会消耗额外的内存和时间，而且会使代码更复杂。使用c语言编写此代码需要注意释放内存，因为内存是由程序员管理的。
最后，正如官方所说，本题考验的是指针的操作能力，本题对于经验稍差的同学来说，容易出现引用空指针的问题，望各位注意一下。

代码如下：

~~~c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void del(struct ListNode * p){
	struct ListNode * temp = p->next;
	p->next = p->next->next;
	free(temp);
}
struct ListNode * deleteDuplicates(struct ListNode * head){
    struct ListNode * temp = head;
	while(head != NULL && head->next != NULL)
	{
        if(head->val == head->next->val)
        {
            del(head);
        }
        else
        {
            head = head->next;
        }
	}
    return temp;
}
~~~





