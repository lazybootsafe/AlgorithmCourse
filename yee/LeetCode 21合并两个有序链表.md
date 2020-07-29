# LeetCode 21|合并两个有序链表

+++

## 原题地址

<https://leetcode-cn.com/problems/merge-two-sorted-lists/>



## 题意

将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的

**示例：**

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```



## 题解

1.判断是否为空
2.比较两个链表的第一个结点值，确定head
3.两个指针指向当前链表的第一个结点
4.循环遍历两个链表，比较值的大小，小的值加入head链表，并把它的指针++
5.若一个链表已经循环完毕，直接将另一个链表加入head

~~~c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)//判空
        return l2;
    if(l2 == NULL)
        return l1;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *head = NULL;
    if(p1->val > p2->val)//先确定头结点
    {
        head = p2;
        p2 = p2->next;
    }    
    else
    {
        head = p1;
        p1 = p1->next;
    } 
    struct ListNode *current = head;//current始终指向head链表的最后一个节点
    while(1)
    {
        if(p1 != NULL && p2 != NULL)//两个链表都没到结尾
        {
            if(p1->val > p2->val)
            {
                current->next = p2;
                current = p2;
                p2 = p2->next;
            }
            else
            {
                current->next = p1;
                current = p1;
                p1 = p1->next;
            }
        }
        if(p1 == NULL)//p1链表为空，就把剩下的p2链表直接加入head末尾
        {
            current->next = p2;
            break;
        }
        if(p2 == NULL)//p2链表为空，就把剩下的p1链表直接加入head末尾
        {
            current->next = p1;
            break;
        }
    }
    return head;   
}
~~~

递归的方法：

~~~c
if (!l1)
		return l2;
	if (!l2)
		return l1;
	if (l1->val < l2->val){
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
~~~

