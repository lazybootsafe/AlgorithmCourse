# LeetCode 20 |  有效的括号

+++

## 原题地址

<https://leetcode-cn.com/problems/valid-parentheses/>



## 题意

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

~~~
输入: "()"
输出: true
~~~

示例 2:

~~~
输入: "()[]{}"
输出: true
~~~





## 题解

首先这个题的突破点，在于括号的ASCII码的转换，或者栈的应用。前者，我没考虑到，后者，我尝试过。但是不得其精髓。
 本次的代码应该有四份的，我总共独自写了三次。第四次，我屈服了去评论区看别人的了。当然不是简单的做了四次。期间小问题也遇到不少。

**自闭之路：**

1. 因为上个题的原因，我个人就一直在想着如何通过拿到这个题的反向解法，就是判断他什么时候为false，就可以直接return。不用遍历全部了。后面是因为我没有想到如何将已经组合配对的括号从序列中剔除掉。就不了了之。
2. 上面就是第一个版本了，现在是第二个，就是直接暴力解决，把这个字符串先遍历一遍，分为两个数组（一个左括号，一个右括号）存起来，然后再一对一的判断，只要出现了不匹配就直接return false。代码如下，超时了。

~~~c
int number = strlen(s),leftNmuber=0,rightNmber=0;
    char left[number],right[number];
    if (s== ""||s==NULL||number==0)
        return true;

    if (number%2==1)
        return false;
    if (s[0]==s[number-1]||s[0]=='}'||s[0]==')'||s[0]==']')
        return false;
    for (int j = 0; j < number; ++j) {
        if (s[j]==')'||s[j]=='}'||s[j]==']'){
            right[rightNmber]=s[j];
            rightNmber++;
        }else{
            left[leftNmuber]=s[j];
            leftNmuber++;
        }

    }
    if (leftNmuber!=rightNmber)
        return false;
    else{
        for (int k = 0; k <rightNmber ; ++k) {
            if ((left[k]=='('&&right[k]==')')||(left[k]=='{'&&right[k]=='}')||(left[k]=='['&&right[k]==']')){
                continue;
            }
            else
                return false;
        }
    }

    return true;

}
~~~



第三个版本，还是基于第二个版本，但用了一个数组，因为第二组数组不需要存，因为在你第一次遍历的时候，存左括号的同时，就可以去判断右括号，是否是配对的，如果不是直接return false，如果是继续循环，最终return。和上个一样，本地ide执行，都是没问题的。LeetCode超时了。代码见下：

~~~c
int number = strlen(s),rightNmber=0,leftNumber=0,rorl;
    if (s==NULL||number==0)
        return true;
    char left[number/2];
    if (s[0]==s[number-1]||s[0]=='}'||s[0]==')'||s[0]==']'||number%2==1)
        return false;
    if (s[0]=='{'||s[0]=='('||s[0]=='[')
        rorl=1;
    else
        rorl=0;
    for (int i = 0; i < number ; ++i) {
        if (rorl==1){
            if (s[i]=='{'||s[i]=='('||s[i]=='['){
                left[leftNumber]=s[i];
                leftNumber++;
                continue;
            } else{
                if (left[rightNmber]=='{'){
                    if (s[i]!='}')
                        return false;
                } else if (left[rightNmber]=='['){
                    if (s[i]!=']')
                        return false;
                }else if (left[rightNmber]=='('){
                    if (s[i]!=')')
                        return false;
                }
            }
            rightNmber++;
        } else{
            if (s[i]==']'||s[i]=='}'||s[i]==')'){
                left[leftNumber]=s[i];
                leftNumber++;
                continue;
            } else{
                if (left[rightNmber]==']'){
                    if (s[i]!='[')
                        return false;
                } else if (left[rightNmber]=='}'){
                    if (s[i]!='{')
                        return false;
                }else if (left[rightNmber]==')'){
                    if (s[i]!='(')
                        return false;
                }
            }
            rightNmber++;
        }
    }
    return true;
}
~~~



4.参考了[大佬写的算法](https://leetcode-cn.com/problems/valid-parentheses/solution/cyu-yan-jian-jian-dan-dan-de-ji-xing-dai-ma-jie-14/)，真的是差距巨大，也是再一次意识到了数据结构的重要性，之前都是了解到这些概念，从未去实践使用过。发现真的代码还是要多实践，也是要多看看别人的代码。独立固然很好，但是独立也一味这没有多元化，也就是一个人的想法总是抵不过这个开源世界的诸多良策的。自己做完了，或者实在做不出来了。看看别人的代码，的确大有裨益。

- **主要的思想其实还是先把一侧的括号存起来，然后把另一侧的拿过来判断，主要是有个指向栈顶的东西，相信大家看到代码就很容易懂得。**



~~~c
bool isValid(char * s){
    if (s == NULL || s[0] == '\0') return true;
    char stack[10240]; int top =0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack[top++] = s[i];
        else {
            if ((--top) < 0)                      return false;//先减减，让top指向栈顶元素
            if (s[i] == ')' && stack[top] != '(') return false;
            if (s[i] == ']' && stack[top] != '[') return false;
            if (s[i] == '}' && stack[top] != '{') return false;
        }
    }
    return (top ? false : true);//防止“【”这种类似情况
}
int main(){
    char *s = "";
    if (isValid(s))
        printf("true");
    else
        printf("false");
    return 0;
}
~~~

