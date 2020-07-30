# LeetCode 148|排序链表

+++

## 原题地址

<https://leetcode-cn.com/problems/sort-list/>



## 题意

在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

```
输入: 4->2->1->3
输出: 1->2->3->4
```

示例 2:

```
输入: -1->5->3->4->0
输出: -1->0->3->4->5
```



## 题解

使用qsort函数

~~~c
#define MAX_LEN 1000

int Cmp(const void *a, const void *b) 
{
    return *(int *)a - *(int *)b;
}
struct ListNode* sortList(struct ListNode* head)
{
    struct ListNode *node = head;
    int num = 0;
    while (node != NULL) {
        num++;
        node = node->next;
    }
    int *tmpNum = (int *)calloc(num, sizeof(int));
    node = head;
    num = 0;
    while (node != NULL) {
        tmpNum[num++] = node->val;
        node = node->next;
    }
    qsort(tmpNum, num, sizeof(int), Cmp);
    node = head;
    num = 0;
    while (node != NULL) {
        node->val = tmpNum[num++];
        node = node->next;
    }

    return head;
}
~~~

