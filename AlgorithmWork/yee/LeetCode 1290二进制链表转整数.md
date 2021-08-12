# LeetCode 1290|二进制链表转整数

+++

## 原题地址

<https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/>



## 题意

给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。

样例：

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/12/15/graph-1.png)

```
输入：head = [1,0,1]
输出：5
解释：二进制数 (101) 转化为十进制数 (5)
```



## 题解

1.刚开始我天真的反转链表

~~~c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    struct ListNode *temp,*local;
    int n,sum;
    local = NULL;
    while(head){
        temp = head->next;
        head->next = local;
        local = head;
        head = temp;
    }
    n = 1;
    sum = 0;
    while(local){
        sum = sum + (n * local->val);
        n = n * 2;
        local = local->next;
    }
    return sum;
}
~~~

2.看了聪明的大佬的方法，使用位运算

~~~c
int getDecimalValue(struct ListNode* head){
    int result = 0;
    while(head){
        result <<= 1;
        result |= head->val;
        head = head->next;
    }

    return result;

}
~~~



3.再厉害的大佬直接直接不用

~~~c
int getDecimalValue(ListNode* head) {
    ListNode *cur = head;
    int res = 0;
    while(cur)
    {
            res = res*2 + cur->val;
            cur = cur->next;
    }
     return res;
}
~~~



