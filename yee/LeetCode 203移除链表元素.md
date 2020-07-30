# LeetCode 203|移除链表元素

+++

## 原题地址

<https://leetcode-cn.com/problems/remove-linked-list-elements/>



## 题意

删除链表中等于给定值 ***val\*** 的所有节点。

**示例:**

```
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```



## 题解

链表具有天然的递归性

![image.png](https://pic.leetcode-cn.com/2393bd26d607f8b20197449633c457535763fae6619fe0559e39da1bd18a1c52-image.png)

可以把上图中的第二个链表看成节点 0 后面挂接了一个更短的链表，比第一个链表少了一个节点；

这个更短的链表可以看成 1 作为头节点的链表，这个更短的链表可以继续看成节点 1 后面挂接了一个更更短的链表；

这个更更短的链表可以看成 2 作为头节点的链表，依次类推，空本身可以理解也是一个链表，最基础最平凡的链表。

有了这样的思考，链表中的很多操作，都可以使用递归这种逻辑思维方式来完成。

![image.png](https://pic.leetcode-cn.com/8283e19cdb4421c5997d4c008de2a0bd2c4f462bce23271db8bb2a28aacdb4d6-image.png)

如上图示意，如果头节点对应的数值不等于 val ，原问题的结果就是头节点后面挂接上子问题求得的蓝色的链表，否则，结果就是子问题求得的蓝色的链表。

~~~c
struct ListNode* removeElements(struct ListNode* head, int val){ 
    if (head == NULL) {
        return NULL;
    }     

    //  删除 head 后面值为 val 的元素的链表
    struct ListNode* res = removeElements(head->next, val);
    //  head 节点是要删除的节点
    if (head->val == val) {
        return res;
    } else {
        head->next = res;
        return head;
    }
}
~~~

进一步化简
 直接将 removeElements 的结果存放在 head->next 中，之后只要看 head->val 是否等于待删除的 val

~~~c
struct ListNode* removeElements(struct ListNode* head, int val){ 
    if (head == NULL) {
        return NULL;
    }     

    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;

}
~~~

