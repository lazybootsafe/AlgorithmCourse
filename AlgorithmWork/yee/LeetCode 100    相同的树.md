# LeetCode 100  |  相同的树

+++

## 原题地址

<https://leetcode-cn.com/problems/same-tree/>



## 题意

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

~~~
输入:       1         1
          / \       / \
         2   3     2   3
         
           [1,2,3],   [1,2,3]
           
 输出: true
~~~



示例 2:

    输入:      1          1
              /           \
             2             2  
             
              [1,2],     [1,null,2]
              
              
      输出: false       



## 题解

   先序遍历，递归判断，如果树相同，则对2颗树中的任意节点，子树也都是相同的树。如果遍历过程中发现有一颗子树有叶子节点，而另一颗子树相应的位置没有，或者遍历过程中发现有节点的值不相等，返回false。如果遍历的时候2颗子树同时变成空，或者节点值相同，则相等。整颗树的判断结果，是根节点的判断结果和所有子孙节点判断结果的逻辑与。

  ~~~c
 /*  

   \* Definition for a binary tree node.  

    \* struct TreeNode {  

   \*   int val;  

   \*   struct TreeNode *left;  
    \*   struct TreeNode *right;  

   \* };  

   */  

   bool  isSameTree( struct  TreeNode* p,  struct  TreeNode* q){
     if (p==NULL&&q!=NULL || p!=NULL&&q==NULL)     return   false ;
     if (p==NULL && q==NULL)   return   true ;
     bool  theSame =  false ;
     if (p->val==q->val) theSame= true ;  
     return  theSame&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
} 
  ~~~

