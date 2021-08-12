# LeetCode 86 | 链表基础，一次遍历处理链表中所有符合条件的元素

## LeetCode第86题，Partition List（链表归并）。



本题的官方难度是Medium，点赞1276，反对296，通过率大约41%。总体来说，这题质量一般，通过率有点高，整体难度偏简单，算是一道链表的基础题。对链表熟悉一些的同学来说，问题不大。  



## 题意


我们首先来看下题意，题意是说给定一个链表以及一个整数x，要求根据x来对链表中的元素进行归并，使得链表的前半部分的结果小于x，后半部分的结果大于等于x。其他元素之间的相对顺序保持不变。  


我们来看样例：  

```
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
```

根据3，我们可以将链表当中的元素分成小于3的与大于3的，其中小于3的元素有122，大于等于3的元素有435。我们返回的结果是122和435组成的新链表，并且122和435当中元素的互相顺序没有发生变化。  



## 题解


由于问题当中并没有对我们如何处理链表以及当中的元素做出限制，所以我们可以随意操作这个链表以及其中的数据，很容易想到最简单的方法就是我们根据x将链表当中的元素分成两个部分，分别存入两个链表当中，最后再将这两个链表合并在一起。合并的方式也非常简单，只需要将链表连接在一起即可。  



这种思路非常无脑，几乎不涉及什么难点，只需要遍历链表然后分别插入不同的链表即可，最后再把这两个链表合并成一个就搞定了。  



我们很容易就可以写出代码：


```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        # 创建两个链表
        left = ListNode(0)
        right = ListNode(0)
        # 以及用来遍历这两个链表的指针
        ln = left
        rn = right
        pnt = head
        while pnt is not None:
            # 小于x则插入left，否则插入right
            if pnt.val < x:
                ln.next = ListNode(pnt.val)
                ln = ln.next
            else:
                rn.next = ListNode(pnt.val)
                rn = rn.next
            pnt = pnt.next
        
        # 将left与right合并
        ln.next = right.next
        return left.next
```

这样我们固然做了出来，但是我们是在抛弃原链表的基础上做出来的，毕竟开辟了额外的空间。如果我们想要不创建新的链表来解决这题应该怎么办呢？  



其实也是很简单的，我们可以遍历链表，如果发现了大于等于x的元素就将它挪到链表的最后。这样当我们遍历结束的时候，就完成了链表的操作。这个思路虽然简单，但是在实现的时候有很多坑点，需要特别小心。  



比如我们需要一个值来记录遍历的重点，因为我们在遍历的时候可能会将一些元素挪到链表的最后。所以我们就不能以None来作为终点了，否则会导致死循环。我们需要以大于等于x的第一个元素作为结束点，当遍历到了这个位置的时候结束。还有很多其他关于链表操作的细节，我们可以来查看代码：  


```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        tail = head
        if head is None:
            return None
        
        # 找到结尾，当找到了大于等于x的元素就放入结尾后面
        while tail.next is not None:
            tail = tail.next
            
        # 记录遍历的终点
        end_point = None
        
        pnt = ListNode(0)
        pnt.next = head
        head = pnt

        while pnt.next is not end_point:
            cur = pnt.next
            if cur.val >= x:
                # 插入在末尾
                tail.next = cur
                tail = cur
                # 如果终点是None的话则进行更新
                # end_point只会更新一次
                if end_point is None:
                    end_point = cur
                pnt.next = cur.next
                continue
            pnt = pnt.next
        tail.next = None
        return head.next

```

## 总结


在这题当中，我们面临的问题是操作链表，将链表当中的一些元素提取出来放在链表最后。无论我们是自己创建新的链表来满足条件，还是在原链表的基础上进行修改，算法的复杂度都是一样的，只是空间复杂度不同，也因此带来的编码复杂度也不同。相对来说，第一种做法更加简单一些，第二种稍稍复杂，但是也并不难，只要熟悉链表的基本操作，应该都是可以做出来的。