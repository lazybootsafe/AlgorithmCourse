# LeetCode 234|回文链表

+++

## 原题地址

<https://leetcode-cn.com/problems/palindrome-linked-list/>



## 题意

判断一个链表是否为回文链表

**示例 1:**

```
输入: 1->2
输出: false
```

**示例 2:**

```
输入: 1->2->2->1
输出: true
```





## 题解

快慢指针+反转链表

![回文链表方法二.jpg](https://pic.leetcode-cn.com/04771ebb842b28e91be9a15dce779ad4c8ceaaf6ba267d6fd62fe1a41415b8d3-%E5%9B%9E%E6%96%87%E9%93%BE%E8%A1%A8%E6%96%B9%E6%B3%95%E4%BA%8C.jpg)

代码如下：

~~~c
void cut(struct ListNode* head,struct ListNode* cutNode);
struct ListNode* reverse(struct ListNode* head);
bool IsEqual(struct ListNode* l1,struct ListNode* l2);

bool isPalindrome(struct ListNode* head){
    if(head==NULL || head->next==NULL) return true;
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;            //慢指针走一步，快指针走两步，最后把单链表分为以慢指针分成两部分
        slow=slow->next;
    }
    cut(head,slow);
    if(fast!=NULL) slow=slow->next;    //如果是奇数个结点，那么cut后将slow后移一位再reverse，就将中间的结点扔掉了，但其实不这么做也是可以的，因为在IsEqual函数中while的判断条件里是&&，即使不把中间的点扔掉，它也不会加入判断，结果是一样的
    return IsEqual(head,reverse(slow));
}
void cut(struct ListNode* head,struct ListNode* cutNode){ //在slow结点前砍断链表
    while(head->next!=cutNode)
        head=head->next;
    head->next=NULL;
}
struct ListNode* reverse(struct ListNode* head)  //头插法*****反转后面一部分(头插法应熟练掌握)
{
    struct ListNode* newHead=NULL;
    while(head!=NULL)
    {
        struct ListNode* nextNode=head->next;
        head->next=newHead;
        newHead=head;
        head=nextNode;
    }
    return newHead;
}
bool IsEqual(struct ListNode* l1,struct ListNode* l2){
    while(l1!=NULL && l2 !=NULL)
    {
        if(l1->val != l2->val) return false;
        l1=l1->next;
        l2=l2->next;
    }
    return true;
}
~~~

