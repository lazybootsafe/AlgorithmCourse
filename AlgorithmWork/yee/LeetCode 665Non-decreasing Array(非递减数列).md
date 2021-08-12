# LeetCode 665|Non-decreasing Array(非递减数列)

## 原题地址

<https://leetcode.com/problems/non-decreasing-array/>

## 题意

给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。

我们来看样例：

```
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
```

```
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
```

题目中给的例子太少，不能覆盖所有情况，我们再来看下面三个例子：
4，2，3
-1，4，2，3
2，3，3，2，4
我们通过分析上面三个例子可以发现，当我们发现后面的数字小于前面的数字产生冲突后，
[1]有时候需要修改前面较大的数字(比如前两个例子需要修改4)，
[2]有时候却要修改后面较小的那个数字(比如前第三个例子需要修改2)，
那么有什么内在规律吗？是有的，判断修改那个数字其实跟再前面一个数的大小有关系，
首先如果再前面的数不存在，比如例子1，4前面没有数字了，我们直接修改前面的数字为当前的数字2即可。
而当再前面的数字存在，并且小于当前数时，比如例子2，-1小于2，我们还是需要修改前面的数字4为当前数字2；
如果再前面的数大于当前数，比如例子3，3大于2，我们需要修改当前数2为前面的数3。

## 题解

题目给出的条件中有两点：①只允许修改一个数字；②修改后数列为非递减数列；

基于这两点需求，我们可以推演一下：符合条件的数组，以逆序点为分界线，分别构成了前、后两段非递减数组，并且在修改逆序点后，两段非递减数组会成功合并为一段非递减数组；如若不成立，此时数组不符合题目要求，return false；

那么我们的判定条件的优先级别如下：

     ①两个指针（在数组中表达为下标序号即可,这里假设为a，b）分别从首尾出发，寻找第一个非有序位置；如果a,b两个指针相隔大于1，此时两段非递减数组不是相邻数组，直接返回false；

例如：

输入: [4,2,1]      //此时a在0,b在2,直接判定false;

//首指针a寻找第一个nums[a]>nums[a+1]的位置，尾指针b寻找第一个nums[b]<nums[b-1]的位置；

      
      ②当a,b相邻或相等时，我们修改值的范围便是前段非递减数列的MAX与后段非递减数列的MIN；即在【nums[a-1]，nums[b+1]】的左右闭区间内，此时如果nums[a-1]>nums[b+1],那么取值区间为空，则不成立，return false；

    ③符合以上基本条件的同时，考虑处理特殊情况，在本题中特殊情况为：a==0||b==numsSize-1；此时为了保险起见，将a,b直接修改为INT_MIN/INT_MAX，如果修改后仍然存在逆序，即则return false；   

   例如：		输入: [3,2···]      //此时a在0,将a修改为INT_MIN；
					  输入: [···3,2]     //此时b在numsSize-1,将b修改为INT_MAX；

代码如下：

~~~c
bool checkPossibility(int* nums, int numsSize) {
      int a= 0,b = numsSize - 1;  //a,b首尾指针；
        while(a< b && nums[a] <= nums[a + 1])  
            a++;  //先从a开始判定，无论a走到哪里，b指针在前进时都不会越过a，给b的判定减少计算了；
        while(a < b && nums[b] >= nums[b - 1])  
            b--;  //题干要求非递减，故判定时使用>=;
        int head = 0;  
        if(a == 0)  
            head = INT_MIN;  
        else  
 
            head = nums[a - 1];  //这里a的修改也可以写成b这种判定表达式，两种方式中a更直观，但更推荐b；
 
       /*  int head=(a==0)?INT_MIN:nums[a-1];*/
 
        int next = (b==numsSize - 1)?INT_MAX:nums[b + 1];  
        if( b - a <= 1 && (head <= nums[b] || nums[a] <= next))  
            return true;  //判定条件中第一条便是a,b的相对位置，如若不满足直接跳出判定，然后是区间判定，本数值区间是否有效，若无效则return false；
        else  
            return false;  
    }  
~~~

如果想让代码更加简洁，可以做如下处理：

~~~c
bool checkPossibility(int* nums, int numsSize) {  
 
  int cnt = 1;   //加入计数器cnt,如
 
  int n = numsSize;    int i;    
 
for ( i = 1; i < n; ++i)    
 
 {  
 
     if (nums[i] < nums[i - 1])        
 
       {  if (cnt == 0)               
 
              return false;//计数器等于0时直接跳出;           
 
 if (i == 1 || nums[i] >= nums[i - 2])        
 
         nums[i - 1] = nums[i];          
 
          else    nums[i] = nums[i - 1];      
~~~

这种做法唯一的问题在于修改了nums中的一个元素，在题目中我们固然可以这样做，但现实操作中这样可能得不偿失