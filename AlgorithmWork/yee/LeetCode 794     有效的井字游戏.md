# LeetCode 794  |   有效的井字游戏

+++

## 原题地址

<https://leetcode-cn.com/problems/valid-tic-tac-toe-state/>



## 题意

用字符串数组作为井字游戏的游戏板 board。当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。

该游戏板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。
“X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。

示例 1:

~~~
输入: board = ["O  ", "   ", "   "]
输出: false
解释: 第一个玩家总是放置“X”。
~~~

示例 2:

~~~
输入: board = ["XOX", " X ", "   "]
输出: false
解释: 玩家应该是轮流放置的。
~~~





## 题解

本题就是确定这盘棋局是不是能够出现的那种，就这样。

 这里有下列几个不合理的棋局：

1. O的数量多于X的数量
2. 存在两个以上的赢法

 错的，理解有误，并不是单纯的存在两个以上就会有错误，而是，emmm就是恰好它会出现两个正确，因此它们会相交，并且不是两个人都赢了的那种，两个人都赢自然也不是正确的棋谱，那么就不怎么好办了。

 例如，这样是对的：
 XOX
 OXO
 XOX
 它这个中间的叉最后一个放，那么就没关系，但下面就是错的：
 XXX
 XOX
 OOO
 不能出现两个人都赢，下面的也是错的：
 XXX
 OOO
 XXX
 这样也不对
 XXX
 XOO
 XXX
 或者这样也不对
 XXX
 OXO
 XXX
 大概也不会出现，因为在前面数量检测就无法通过了。
 因此我们在判断是否会赢的时候，只判断是否两个人都会赢，这样返回false，就这样就行。之前提到过，只论赢的话，一共七种赢法，分别是：
 XXX  XYY  XYY  YYX  YYY  YYY  YXY
 YYY  XYY  YXY  YXY  XXX  YYY  YXY
 YYY  XYY  YYX  XYY  YYY  XXX  YXY
  1    2    3     4    5     6    7

 XXX
 XOO
 OO
 这样也是不对的，为什么呢？因为如果一旦甲胜利了，他的棋子就会比乙多一个，如果乙胜利了，他的棋子就跟甲的一样多，因此你可以：
 如果甲乙棋子数量相同，就判断
   是不是乙赢了。。。不行，太难了

 用递归的方法，递归出所有可行的解，挨个测试。
 失败了，它有时间限制！！！虽然它只是一个九宫格，不代表你能随便用，它可能一次用大量数组，最好不要遍历进行暴力破解。

 因此我们多用if来限制吧：
 甲乙棋子数量相同
   是不是二者都赢了，返回false，其余返回true
   是不是甲赢了，如果甲赢了返回false，否则返回true
 甲比乙多一个棋子
   是不是二者都赢了，返回false，其余返回ture
   是不是乙赢了，如果乙赢了返回false，否则返回true

 事实证明，通过了，原始代码如下：

~~~cpp
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int X_n=0, O_n=0;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(board[i][j] == 'X') X_n++;
                else if(board[i][j] == 'O') O_n++; 
        // 判断阶段
        if(X_n-O_n==0){ // 棋子相同 不允许甲赢
            if(bothWin(board)){return false;}
            else{
                if(isXWin(board)) return false;
                else return true;
            }
        }
        if(X_n-O_n==1){ // 棋子不同不允许乙赢
            if(bothWin(board)){return false;}
            else{
                if(isOWin(board)) return false;
                else return true;
            }
        }
        return false;
    }
    // 是不是二者都赢了
    bool bothWin(vector<string>& board){
        int win[256] = {0};
        if(isLink(board[0][0], board[0][1], board[0][2])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][0], board[2][0])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][1], board[2][2])) win[board[0][0]]++;
        if(isLink(board[0][1], board[1][1], board[2][1])) win[board[0][1]]++;
        if(isLink(board[0][2], board[1][1], board[2][0])) win[board[0][2]]++;
        if(isLink(board[1][0], board[1][1], board[1][2])) win[board[1][0]]++;
        if(isLink(board[2][0], board[2][1], board[2][2])) win[board[2][0]]++;
        if(win['X'] * win['O']) return true; 
        else return false;
    }
        // 是不是甲赢了
    bool isXWin(vector<string>& board){
        int win[256] = {0};
        if(isLink(board[0][0], board[0][1], board[0][2])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][0], board[2][0])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][1], board[2][2])) win[board[0][0]]++;
        if(isLink(board[0][1], board[1][1], board[2][1])) win[board[0][1]]++;
        if(isLink(board[0][2], board[1][1], board[2][0])) win[board[0][2]]++;
        if(isLink(board[1][0], board[1][1], board[1][2])) win[board[1][0]]++;
        if(isLink(board[2][0], board[2][1], board[2][2])) win[board[2][0]]++;
        if(win['X'] ) return true; 
        else return false;
    }
        // 是不是乙赢了
    bool isOWin(vector<string>& board){
        int win[256] = {0};
        if(isLink(board[0][0], board[0][1], board[0][2])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][0], board[2][0])) win[board[0][0]]++;
        if(isLink(board[0][0], board[1][1], board[2][2])) win[board[0][0]]++;
        if(isLink(board[0][1], board[1][1], board[2][1])) win[board[0][1]]++;
        if(isLink(board[0][2], board[1][1], board[2][0])) win[board[0][2]]++;
        if(isLink(board[1][0], board[1][1], board[1][2])) win[board[1][0]]++;
        if(isLink(board[2][0], board[2][1], board[2][2])) win[board[2][0]]++;
        if(win['O']) return true; 
        else return false;
    }
    // 三个字符是否相同
    bool isLink(char ch1, char ch2, char ch3){
        if(ch1 == ' ') return false;
        if(ch1 == ch2){
            if(ch2 == ch3){
                return true;
            }
        }
        return false;
    }
 
};
~~~

