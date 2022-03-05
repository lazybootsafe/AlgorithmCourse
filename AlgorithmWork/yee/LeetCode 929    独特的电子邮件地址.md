# LeetCode 929  |  独特的电子邮件地址

+++

## 原题地址

<https://leetcode-cn.com/problems/unique-email-addresses/>



## 题意

每封电子邮件都由一个本地名称和一个域名组成，以 @ 符号分隔。

例如，在 alice@leetcode.com中， alice 是本地名称，而 leetcode.com 是域名。

除了小写字母，这些电子邮件还可能包含 '.' 或 '+'。

如果在电子邮件地址的本地名称部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名称中没有点的同一地址。例如，"alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。 （请注意，此规则不适用于域名。）

如果在本地名称中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件，例如 m.y+name@email.com 将转发到 my@email.com。 （同样，此规则不适用于域名。）

可以同时使用这两个规则。

给定电子邮件列表 emails，我们会向列表中的每个地址发送一封电子邮件。实际收到邮件的不同地址有多少？

 示例：

~~~
输入：["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
输出：2
解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。


提示：

1 <= emails[i].length <= 100
1 <= emails.length <= 100
每封 emails[i] 都包含有且仅有一个 '@' 字符。
~~~



## 题解

读懂这个题目就已经做对了有一半了。创建两个数组，一个二维数组A保存要发送的邮件地址，另外一个一维数组temp保存每次发送的临时邮件地址；遍历入参二维数组email，按照题目给定的规则逐行进行解析并将结果保存在temp中，将temp中保存的邮件地址与A组行比较，如果A中不存在该邮件地址则将该地址复制到A中且A中的行数加1，直至email遍历完成，返回A的行数即可。

~~~c
#define CHARMAX 100

int numUniqueEmails(char ** emails, int emailsSize){
    char **arr = NULL;
    char *temp = NULL;
    int row, col, i, idx;

    arr = (char **)malloc(sizeof(char *) * emailsSize);
    for (i = 0; i < emailsSize; i++) {
        arr[i] = (char *)malloc(sizeof(char) * CHARMAX);
        memset(arr[i], 0, sizeof(char) * CHARMAX);
    }

    temp = (char *)malloc(sizeof(char) * CHARMAX);

    for (row = 0, idx = 0; row < emailsSize; row++) {
        col = 0;
        i = 0;
        memset(temp, 0, sizeof(char) * CHARMAX);

        while (emails[row][col] != '\0') {
            if (emails[row][col] == '@') {
                strcat(&temp[i], &emails[row][col]);
                break;
            } else if (emails[row][col] == '.') {
                col++;
                continue;
            } else if (emails[row][col] == '+') {
                while (emails[row][col] != '@') {
                    col++;
                }
            } else {
                temp[i++] = emails[row][col];
                col++;
            }
        }

        for (i = 0; i < idx; i++) {
            if (strcmp(temp, arr[i]) == 0) {
                break;
            }
        }

        if (i == idx) {
            strcpy(arr[idx], temp);    
            idx++;
        }
    }

    for (i = 0; i < emailsSize; i++) {
        free(arr[i]);
    }
    free(arr);
    free(temp);

    return idx;
}
~~~



