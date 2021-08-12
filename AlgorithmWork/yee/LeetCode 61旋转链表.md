# LeetCode 61|旋转链表

+++

## 原题地址

<https://leetcode-cn.com/problems/rotate-list/>



## 题意

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

~~~
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
~~~



示例 2:

~~~
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
~~~



## 题解

**链表成环解环**

既然是旋转，就与环有关。
解法思路：

    先遍历链表求长度 n，并把链表成环；
    根据 k 与 n 的关系决定 遍历链表的步数；
    
    k == n 或 n == 1 时，直接返回;
    k > n 时， k = n - (k % n) - 1;
    k < n 时， k = n - k - 1;
    
    往前走 k 步后，当前结点 next 域置空（解环），返回后一个结点
    
    因为题中的旋转是 逆向 的，而我们只能按着 链表正向遍历，所以要先用 n 去剪；

~~~c
struct ListNode* rotateRight(struct ListNode* head, int k) {
  if (k <= 0 || head == NULL) return head;
  int n = 1;
  struct ListNode* p = head;
  while (p->next != NULL) {  // 求长度
    p = p->next;
    n++;
  }
  if (n == k || n == 1)  // 求位置
    return head;
  else if (k > n)
    k = n - (k % n) - 1;
  else
    k = n - k - 1;
  p->next = head;  // 链表成环
  p = head;        // 重新搜索
  while (k > 0) {
    p = p->next;
    k--;
  }
  head = p->next;  // 链表解环
  p->next = NULL;
  return head;
}
~~~

