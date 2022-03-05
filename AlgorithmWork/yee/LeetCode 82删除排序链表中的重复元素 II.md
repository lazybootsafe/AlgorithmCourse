# LeetCode 82|删除排序链表中的重复元素 II

+++

## 原题地址

<https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/>



## 题意

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 *没有重复出现* 的数字。

示例 1:

~~~
输入: 1->2->3->3->4->4->5
输出: 1->2->5
~~~

示例 2:

~~~
输入: 1->1->1->2->3
输出: 2->3
~~~



## 题解

双指针法，一个pre一个p,pre永远在p前面，且控制pre在重复值节点之前，如3->2->2->2->2->2，pre只能处于值为3的节点，而不能在值为2的节点。
利用val记录上一个节点的值，将当前节点的值与val比较。①如果不相等，则利用当前节点的值更新val，并且pre和p指针都向后移；②如果相等，则p指针回溯到pre的后一位，接着对p节点的值与val比较，相同则删除该节点，然后p指针往后移重复上述步骤，直至p节点值与val不相等，然后回到①的步骤。
（有一个flag变量用来保证从情况②切换到情况①时pre指针在p前面）

~~~ c
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL){
        return head;
    }
    //建立头结点，声明两个指针pre和p,pre永远位于p的前面，方便对于p的删除
    struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode)),*pre=h,*p=head->next;
    h->next=head;
    //利用val存储上一个节点的值
    int val=head->val,flag=0;
    while(p!=NULL){
        if(val!=p->val){//如果现在的节点与上个节点的值不同
            val=p->val;
            if(flag!=1){
                pre=pre->next;
            }
            p=p->next;
            flag=0;
        }else{
            p=pre->next;  //让p回到pre的后一位,将全部等于val的节点删除
            pre->next=pre->next->next;
            free(p);
            p=pre->next;
            flag=1;
        }
    }
    head=h->next;
    free(h); //记得把辅助头节点占用的空间释放！！！
    return head;
}
~~~



