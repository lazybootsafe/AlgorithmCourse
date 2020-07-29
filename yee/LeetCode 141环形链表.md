# LeetCode 141|环形链表

+++

## 原题地址

<https://leetcode-cn.com/problems/linked-list-cycle/>



## 题意

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

样例：

```
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)



## 题解

快慢指针法：

1. 定义两个指针，刚开始均指向头结点；
2. 快指针走两步，慢指针走一步；
3. 如果存在环，则快慢指针必然会相遇。

如下图所示：

![image.png](https://pic.leetcode-cn.com/486b24c0f0b85c2106a7567e399c12e84688dea1243a9abe927b8270dafc9650-image.png)

代码如下：

~~~C
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while((fast != NULL) && (fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }
    }
    
    return false;
}
~~~

