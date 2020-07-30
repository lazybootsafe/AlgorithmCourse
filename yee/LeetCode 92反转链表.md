# LeetCode 92|反转链表||

+++

## 原题地址

<https://leetcode-cn.com/problems/reverse-linked-list-ii/>



## 题意

反转从位置 *m* 到 *n* 的链表。请使用一趟扫描完成反转。
（1 ≤ *m* ≤ *n* ≤ 链表长度。）

示例:

~~~
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

~~~



## 题解

思路：

反转链表示例：

![image.png](https://pic.leetcode-cn.com/3f2c3822970edc99db4fbf390ea7059eb5ee0e5ace94acaa27333eb014b5b9a1-image.png)

![image.png](https://pic.leetcode-cn.com/1b3738692d64f05bf571ec45b4b1c935ac068a938700181675fad0da80d68726-image.png)

表示：

    head移动m-1个位置指向逆置段逆置前头结点；
    pre_head指向逆置段头结点的前驱；
    modify_list_tail指向逆置段逆置后尾节点；
    new_head指向逆置段逆置后头节点
    result指向反转后链表的头结点，初始值为head。
    首先将pre_head指向NULL
    

***步骤一：***

![image.png](https://pic.leetcode-cn.com/a9208d4275956bc70ee965d968d25bbc99f3720c7acddc0cc258f0472bdfee97-image.png)

***步骤二：***

![image.png](https://pic.leetcode-cn.com/53323588223a933bd8f194dde12fd0d32772de4649df59ea526cc97852b0e811-image.png)

***步骤三：***

![image.png](https://pic.leetcode-cn.com/fc764417411f108f4537db05da9396dca0d65028e7386e21c5b08816970f6ba2-image.png)

*若*m!=1，则*pre_head*非空，直接返回*result*；
 若*m==1*，则*pre_head*为空，则*result=new_head*,返回*result*。



~~~c
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    int change_len=n-m+1;
    struct ListNode *pre_head=NULL;
    struct ListNode *result=head;

    while(--m)
    {
        pre_head=head;
        head=head->next;
    }
    struct ListNode *modify_list_tail=head;
    struct ListNode *new_head=NULL;
    while(change_len)
    {
        struct ListNode *next=head->next;
        head->next=new_head;
        new_head=head;
        head=next;
        change_len--;
    }
    modify_list_tail->next=head;
    if(pre_head)
    {
        pre_head->next=new_head;
    }
    else
    {
        result=new_head;
    }
    return result;
}
~~~

