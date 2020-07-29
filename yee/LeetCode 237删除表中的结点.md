# LeetCode 237|删除表中的结点

+++

## 原题地址

<https://leetcode-cn.com/problems/delete-node-in-a-linked-list/>

## 题意

编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点

现有一个链表 -- head = [4,5,1,9]，它可以表示为:

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/01/19/237_example.png)

我们来看样例：

~~~
输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
~~~



## 题解

很容易想到，把下一个节点的val和next字段的值，都复制到当前节点上，然后删除下一个节点。

考虑到通用性，节点的拷贝应当避免显示指定成员变量：

~~~c
node->val = node->next->val;
node->next = node->next->next;
~~~



而是应当用=操作符，或者显示地memcpy:

~~~c
memcpy(node, node->next, sizeof(struct ListNode));//or: *node = *(node->next);
//为什么是*node = *(node->next); 而不是node=node->next呢？
//因为结构是可以直接复制的，这样其实是把后一个节点的内容复制到这个节点
//node=node->next，而这样只是改了指针的指向
~~~



此外，题目的意思是删除节点，应当是要释放一个节点大小的内存，而不是“跳过去”，因此在开始拷贝下一个节点各个字段的值到当前节点之前，应当标记后一个节点，等赋值结束后，删除此标记节点。完整代码如下：

~~~c
void deleteNode(struct ListNode* node) {
    struct ListNode* shadow = node->next;
    memcpy(node, node->next, sizeof(struct ListNode));//or: *node = *(node->next);
    free(shadow);
    shadow = NULL;
}
~~~

