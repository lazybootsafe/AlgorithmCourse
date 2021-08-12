# LeetCode 1171|从链表中删去总和值为零的连续节点

+++

## 原题地址

<https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/>



## 题意

给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。

删除完毕后，请你返回最终结果链表的头节点。

 示例 1：

~~~
输入：head = [1,2,-3,3,1]
输出：[3,1]
提示：答案 [1,2,1] 也是正确的。
~~~

示例 2：

~~~
输入：head = [1,2,3,-3,4]
输出：[1,2,4]
~~~



## 题解

两重循环暴力搜索所有可能的子序列

~~~C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeZeroSumSublists(struct ListNode* head) {
	if (!head) return head;
	struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
	L->next = head;
	struct ListNode* p = L;
	struct ListNode* q = L->next;
	while (p) {
		q = p->next;
		int sum = 0;
		while (q) {
			sum += q->val;
			if (sum == 0) break;
			q = q->next;
		}
		if (q) {
			p->next = q->next;
		}
		else {
			p = p->next;
		}
	}
	return L->next;
}
~~~

