# LeetCode 725|分割链表

+++

## 原题地址

<https://leetcode-cn.com/problems/split-linked-list-in-parts/>



## 题意

给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。

每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。

这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。

返回一个符合上述规则的链表的列表。

举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]

示例 1：

~~~
输入: 
root = [1, 2, 3], k = 5
输出: [[1],[2],[3],[],[]]
解释:
输入输出各部分都应该是链表，而不是数组。
例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
~~~



## 题解

题目理解:把一个链表分割成K个连续的部分，要求任意两部分的长度差距不能超过1，前面的部分的长度应该大于等于后面部分的长度，有些部分可能为NULL。[就是类比给n个孩子分k个苹果，先平均分，然后剩下的苹果从前往后一个个给]

![分隔链表.jpg](https://pic.leetcode-cn.com/8d362375b1b40f1a52254240d1e92af233b53c1877c8da1eb056ecc7581dda3f-%E5%88%86%E9%9A%94%E9%93%BE%E8%A1%A8.jpg)

总体思路:类比给k个孩子分N个苹果，先平均分，再把多的从头往后分(实际操作时，是两个部分一起分的，因为要按照原来的顺序分)
1.申请内存(注意是二维指针)[一段连续二维指针，便可写成数组的格式，用下标访问，output[i]对应的是第i个链表的表头]
2.遍历链表得到length,算出mod-平均分完后多出来的结点数,size-每个部分本应有的结点数
3.循环 分割链表(注意特殊情况:length<k,k以后的部分都应是NULL)
3中的亮点:curSize的计算
注意点:还有一个 *returnSize 参数需要赋值。 (因为传进来的是指针，直接赋值即可)

~~~c
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    struct ListNode** output=(struct ListNode**)malloc(k*sizeof(struct ListNode*)); //注意申请内存的表达式
    int length=0;
    struct ListNode* cur=root;
    while(cur!=NULL)
    {
        length++;
        cur=cur->next;
    }
    cur=root;                //遍历后不能忘了把指针重置到链表开头/
    int mod=length%k;
    int size=length/k;
    for(int i=0;i<k;i++)
    {
        output[i]=cur;  //如果i<k但是cur==NULL  那么证明是特殊情况(length<k) 只将cur(即NULL)赋给数组元素 后面的都不执行
        if(cur!=NULL)
        {        
            int curSize=size+(mod-- >0? 1:0);            //亮点
            for(int j=0; j<curSize-1; j++) cur=cur->next;   //分割链表
            struct ListNode* next=cur->next;
            cur->next=NULL;
            cur=next;
        }
    }
    *returnSize=k;                //题目中的一个参数(用来返回链表个数？？？)
    return output;
}



~~~

