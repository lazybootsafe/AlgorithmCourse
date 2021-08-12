# LeetCode 1221 | 分割平衡字符串

+++

## 原题地址

<https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/>



## 题意

在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。

给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。

返回可以通过分割得到的平衡字符串的最大数量。

 

示例 1：

~~~
输入：s = "RLRRLLRLRL"
输出：4
解释：s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'。
~~~

示例 2：

~~~
输入：s = "RLLLLRRRLR"
输出：3
解释：s 可以分割为 "RL", "LLLRRR", "LR", 每个子字符串中都包含相同数量的 'L' 和 'R'。
~~~

示例 3：

~~~
输入：s = "LLLLRRRR"
输出：1
解释：s 只能保持原样 "LLLLRRRR".
~~~





## 题解

分割的最大数量， 就是将字符串s切割成一系列的子串，并且字串中R和L的数量要相等，

那问题来了怎莫切割，我们以示例1来看

~~~
示例 1：

输入：s = "RLRRLLRLRL"
~~~

从头开始

R 切割不了

RL 能切割，那到底切不切呢

继续向下看

RLRRLL也可以切割掉

RL 和RLRRLL选哪个呢

很明显题目要求字串数量大，那就肯定切割长度越小的字串越好，切RL，这道题的贪心大概就在这里吧，那么解题思路就很明显了

我们for循环遍历字串，

rcnt代表R的数量，lcnt代表L的数量，cnt代表结果

假使当前字符等于谁，谁的数量就加1，假使rcnt和lcnt刚好相等的时候，不正好就是字串R L数量相等且字串长度最小的时候嘛，那就让rcnt=0，lcnt=0，cnt+=1，最后的cnt就是答案了



~~~cpp
class Solution {
    public int balancedStringSplit(String s) {
        int len = s.length();
        int rcnt=0, lcnt=0, cnt=0;
        for(int i=0; i<len; i++){
            if(s.charAt(i)=='R')
                rcnt++;
            else
                lcnt++;

            if(rcnt==lcnt){
                cnt++;
                rcnt=0;
                lcnt=0;
            }
        }

        return cnt;
    }
}
~~~

