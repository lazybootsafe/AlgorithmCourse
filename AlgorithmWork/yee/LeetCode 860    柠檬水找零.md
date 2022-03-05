# LeetCode 860  |  柠檬水找零

+++

## 原题地址

<https://leetcode-cn.com/problems/lemonade-change/>



## 题意

在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

示例 1：

~~~
输入：[5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
~~~



## 题解

5元的找零能力最强

1.设置两个找零盒, 一个放五元的一个放十元的
2.由于5元的找零能力更强, 于是优先消耗十元找零
3.如果支付的是五元, 直接存入找零盒count_5
4.如果支付的是十元, count_5--, count_10++
5.如果支付的是二十元, 优先count_10--,count_5--, 其次考虑count_5-=3
6.若全部找零方式都无法使用(某个必需的找零盒为空), 则返回False

~~~c
bool lemonadeChange(int* bills, int billsSize){
    int count_5 = 0;
    int count_10 = 0;
    
    for (int i=0; i<billsSize; i++){
        if (bills[i] == 5){
            count_5++;
        }
        else if (bills[i] == 10){
            if (count_5 != 0){
                count_5--;
                count_10++;
            }else{
                return false;
            }
        }else{
            if (count_10 != 0 && count_5 != 0){
                count_5--;
                count_10--;
            }
            else if(count_5 >= 3){
                count_5 -= 3;
            }else{
                return false;
            }
        }
    }
    return true;
}
~~~

