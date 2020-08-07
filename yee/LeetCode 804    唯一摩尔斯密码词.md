# LeetCode 804  |  唯一摩尔斯密码词

+++

## 原题地址

<https://leetcode-cn.com/problems/unique-morse-code-words/>



## 题意

国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如: "a" 对应 ".-", "b" 对应 "-...", "c" 对应 "-.-.", 等等。

为了方便，所有26个英文字母对应摩尔斯密码表如下：

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
给定一个单词列表，每个单词可以写成每个字母对应摩尔斯密码的组合。例如，"cab" 可以写成 "-.-..--..."，(即 "-.-." + ".-" + "-..." 字符串的结合)。我们将这样一个连接过程称作单词翻译。

返回我们可以获得所有词不同单词翻译的数量。

例如:

~~~
输入: words = ["gin", "zen", "gig", "msg"]
输出: 2
解释: 
各单词翻译如下:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

共有 2 种不同翻译, "--...-." 和 "--...--.".


注意:

单词列表words 的长度不会超过 100。
每个单词 words[i]的长度范围为 [1, 12]。
每个单词 words[i]只包含小写字母。
~~~



## 题解

用树解决这一思路是参照了大佬的解题思路，看了好久才稍微领悟

**解题思路：**

用二叉树来解题 -向左枝 .向右枝
每个单词能生成一个自己的“摩尔斯路径”，路径的终点做一个标记。
最后统计标记的数量，就是不同摩尔斯密码的数量。

~~~c
//树的节点
typedef struct Node {
	int num;
	struct Node * left;
	struct Node * right;
}node;
//生成一个节点
node* newNode()
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->num = 0;
	newNode->left = 0;
	newNode->right = 0;
	return newNode;
}
//销毁树,统计数量
void deletTree(node* root, int *sum)
{
	if (root == 0)
		return;

	deletTree(root->left, sum);
	deletTree(root->right, sum);
	*sum += root->num;
	free(root);
}

int uniqueMorseRepresentations(char ** words, int wordsSize) {
	if (wordsSize == 0)return 0;
	//摩尔斯密码词典
	char *s[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
	//建一棵编码树
	node* root = newNode();
	node* iterTree = root;
	//逐单词遍历
	for (int i = 0; i < wordsSize; ++i)
	{
		//第i个单词，逐字母c遍历
		char *c = words[i];
		while (*c != '\0')
		{
			//提取出字母对应的摩尔斯密码
			char *iter = s[(int)(*c - 'a')];
			//根据摩尔斯密码的点和线生成编码树
			while (*iter != '\0')
			{
				//如果是个'-' 向左伸一个枝
				if (*iter == '-')
					if (iterTree->left != 0)
						iterTree = iterTree->left;
					else
					{
						iterTree->left = newNode();
						iterTree = iterTree->left;
					}
				//如果是个'.'向右伸一个枝
				else if (*iter == '.')
					if (iterTree->right != 0)
						iterTree = iterTree->right;
					else
					{
						iterTree->right = newNode();
						iterTree = iterTree->right;
					}
				++iter;
			}
			++c;
		}
		//下一个单词 树又要从根开始延伸
		iterTree->num = 1;
		iterTree = root;
	}
	//多少叶子节点，不同单词翻译数量就是多少
	int sum=0;
	deletTree(root, &sum);
	return sum;
}
~~~

